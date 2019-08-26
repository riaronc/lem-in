/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:05:19 by odushko           #+#    #+#             */
/*   Updated: 2019/07/27 14:05:21 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../inc/lem_in.h"

static void	print_file(char **a)
{
	int	i;

	i = -1;
	while (a[++i])
		if (is_comment(a[i]) != COMMENT)
			ft_putendl(a[i]);
}

static void	init(t_lem *l)
{
	ft_bzero(l, sizeof(t_lem));
	l->fd = 0;
	l->file_tmp = "";
	l->rnum = 0;
	l->num = 0;
	l->q = 0;
	l->q2 = 0;
}

int			main(void)
{
	t_lem	*l;

	if (!(l = (t_lem *)malloc(sizeof(t_lem))))
		error(l, 0);
	init(l);
	if (get_input(l) == 2)
	{
		handle_rooms(l);
		handle_links(l);
		bfs(l) ? create_a_route(l) : error(l, 1);
		ft_putnbr(l->ants);
		ft_putchar('\n');
		print_file(l->file);
		ants_route(l);
	}
	else
		error(l, 1);
	system("leaks -q lem");
	return (0);
}
