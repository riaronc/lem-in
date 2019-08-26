/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:05:41 by odushko           #+#    #+#             */
/*   Updated: 2019/07/27 14:05:44 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		handle_rooms(t_lem *l)
{
	int		i;
	int		j;

	if (!(l->r = (t_room *)malloc(sizeof(t_room) * l->rnum)))
		error(l, 1);
	ft_bzero(l->r, sizeof(t_room) * l->rnum);
	i = -1;
	j = 0;
	while (l->file[++i])
		if (is_comment(l->file[i]) != COMMENT && !is_link(l->file[i]))
		{
			if (!(ft_strcmp("##start", l->file[i])))
				l->r[0].name = ft_strchdup(l->file[++i], ' ');
			else if (!(ft_strcmp("##end", l->file[i])))
				l->r[l->rnum - 1].name = ft_strchdup(l->file[++i], ' ');
			else if (is_comment(l->file[i]) == COMMAND)
				continue ;
			else if (j != l->rnum - 2)
				l->r[++j].name = ft_strchdup(l->file[i], ' ');
			l->i = i;
		}
	if (!l->r[0].name || !l->r[l->rnum - 1].name)
		error(l, 2);
}

static void	add_links(t_lem *l, int p1, int p2)
{
	t_link	*new;
	t_link	*new2;

	if (!(new = (t_link *)malloc(sizeof(t_link))) ||
		!(new2 = (t_link *)malloc(sizeof(t_link))))
		error(l, 1);
	ft_bzero(new, sizeof(t_link));
	ft_bzero(new2, sizeof(t_link));
	new->next = l->r[p2].links;
	new2->next = l->r[p1].links;
	p1 == 0 ? l->r[p1].visited = 1 : 0;
	new->room = l->r[p1];
	p2 == 0 ? l->r[p2].visited = 1 : 0;
	new2->room = l->r[p2];
	l->r[p2].links = new;
	l->r[p1].links = new2;
}

void		handle_links(t_lem *l)
{
	int		p1;
	int		p2;
	int		len;
	char	*name;

	while (l->file[l->i++])
		if (l->file[l->i] && is_link(l->file[l->i]))
		{
			name = ft_strchdup(l->file[l->i], '-');
			p1 = room_pos(name, l);
			len = ft_strlen(name);
			free(name);
			name = ft_strdup(&l->file[l->i][len + 1]);
			p2 = room_pos(name, l);
			free(name);
			if (p1 == -1 || p2 == -1)
				error(l, 2);
			add_links(l, p1, p2);
		}
}
