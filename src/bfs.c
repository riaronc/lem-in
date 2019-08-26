/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:07:25 by odushko           #+#    #+#             */
/*   Updated: 2019/07/27 14:07:27 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		create_a_route(t_lem *l)
{
	int		i;
	t_room	*now;

	i = l->i - 1;
	if (!(l->route = (t_room *)malloc(sizeof(t_room) * l->i)))
		return (0);
	now = &l->r[l->rnum - 1];
	while (now->prev || !ft_strcmp(now->name, l->r[0].name))
	{
		l->route[i--] = *now;
		now = now->prev;
		if (!now)
			break ;
	}
	return (1);
}

void	find_finish(t_lem *l, int *room, int *end)
{
	t_room	*now;

	now = &l->r[*room];
	while (now->links)
	{
		*room = room_pos(now->links->room.name, l);
		if (l->r[*room].visited == 0)
		{
			l->r[*room].visited = 1;
			l->r[*room].prev = now;
			l->queue[++l->q2] = l->r[*room];
			if (*room == l->rnum - 1)
			{
				*end = 1;
				break ;
			}
		}
		now->links = now->links->next;
	}
	*room = room_pos(l->queue[++l->q].name, l);
}

void	prep(t_lem *l)
{
	int i;

	i = -1;
	while (++i < l->rnum)
		l->r[i].visited = 0;
	l->r[0].visited = 1;
	l->queue[0] = l->r[0];
	l->i = 0;
}

int		bfs(t_lem *l)
{
	int		end;
	t_room	*now;
	int		room;

	end = 0;
	if (!(l->queue = (t_room *)malloc(sizeof(t_room) * l->rnum)))
		return (0);
	ft_bzero(l->queue, sizeof(t_room) * l->rnum);
	prep(l);
	room = 0;
	while (!end && room != -1)
		find_finish(l, &room, &end);
	now = &l->r[l->rnum - 1];
	if (end)
		while (now->prev || !ft_strcmp(now->name, l->r[0].name))
		{
			room = room_pos(now->name, l);
			now = now->prev;
			l->i++;
			if (!now)
				break ;
		}
	return (end);
}
