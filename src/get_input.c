/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:05:28 by odushko           #+#    #+#             */
/*   Updated: 2019/07/27 14:05:29 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"
#define GNL(x, y) get_next_line(x, y)

static void	read_file(t_lem *l, char **line)
{
	char	*tmp;

	while (GNL(l->fd, line) > -1 && ft_strlen(*line) > 0)
	{
		if (*line[0] == 'L')
			break ;
		tmp = l->file_tmp;
		l->file_tmp = ft_strjoin(tmp, *line);
		ft_strlen(tmp) ? free(tmp) : 0;
		tmp = l->file_tmp;
		l->file_tmp = ft_strjoin(tmp, "\n");
		free(tmp);
		free(*line);
	}
	free(*line);
	if (GNL(l->fd, line) > -1 && ft_strlen(*line))
	{
		free(*line);
		error(l, 4);
	}
}

int			get_input(t_lem *l)
{
	char	*line;
	int		valid;
	int		i;

	valid = 0;
	GNL(l->fd, &line);
	l->ants = ft_atoi(line);
	free(line);
	if (l->ants < 1 || l->ants > INTMAX)
		error(l, 0);
	read_file(l, &line);
	l->file = ft_strsplit(l->file_tmp, '\n');
	free(line);
	i = -1;
	while (l->file[++i])
	{
		if (!ft_strcmp(l->file[i], "##end") ||
			!ft_strcmp(l->file[i], "##start"))
			valid++;
		if (is_room(l->file[i]))
			l->rnum++;
	}
	free(l->file_tmp);
	return (valid);
}
