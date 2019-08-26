/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:45:14 by odushko           #+#    #+#             */
/*   Updated: 2018/12/15 14:46:51 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

static char		*ft_strcdup(char const *s, char ch)
{
	size_t	i;
	size_t	len;
	char	*dest;

	i = 0;
	len = 0;
	while (s[len] != ch && s[len] != '\0')
		len++;
	dest = (char *)malloc(len + 1);
	while (s[i] != ch && s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static t_list	*ft_file_check(const int fd, t_list **given)
{
	t_list	*neww;

	neww = *given;
	while (neww)
	{
		if (neww->content_size == (size_t)fd)
			return (neww);
		neww = neww->next;
	}
	if (!(neww = ft_lstnew("\0", (size_t)fd)))
		return (NULL);
	ft_lstadd(given, neww);
	return (neww);
}

static int		ft_rw_file(const int fd, char **rw_result)
{
	int		rw_return;
	char	rw_line[BUFF_SIZE + 1];
	char	*buffer;

	while ((rw_return = (int)read(fd, rw_line, BUFF_SIZE)))
	{
		rw_line[rw_return] = '\0';
		buffer = (*rw_result);
		if (!(*rw_result = ft_strjoin(buffer, rw_line)))
			return (-1);
		free(buffer);
		if (ft_strchr(rw_line, '\n'))
			break ;
	}
	return (rw_return);
}

static int		ft_endline(char **line, char **buf, t_list **now, int ret)
{
	int		l_line;
	int		l_buf;
	t_list	*tmp;

	tmp = *now;
	l_line = (int)ft_strlen(*line);
	l_buf = (int)ft_strlen(*buf);
	if (ret < 1 && l_buf == 0)
		return (0);
	if (l_line < l_buf)
		tmp->content = ft_strsub(*buf, l_line + 1, l_buf - l_line - 1);
	*now = tmp;
	free(*buf);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*check;
	t_list			*now;
	char			*buf_line;
	int				rw_return;

	if (fd < 0 || read(fd, "", 0) < 0 || BUFF_SIZE < 1 ||
			!(now = ft_file_check(fd, &check)))
		return (-1);
	buf_line = now->content;
	rw_return = ft_rw_file(fd, &buf_line);
	now->content = buf_line;
	*line = ft_strcdup(buf_line, '\n');
	if (ft_endline(line, &buf_line, &now, rw_return))
		return (1);
	return (0);
}
