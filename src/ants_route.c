/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_route.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:05:51 by odushko           #+#    #+#             */
/*   Updated: 2019/07/27 14:06:02 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static void		print_ant(short which, char *where)
{
	ft_putchar('L');
	ft_putnbr(which);
	ft_putchar('-');
	ft_putstr(where);
	ft_putchar(' ');
}

void			ants_route(t_lem *l)
{
	int now;
	int i;

	now = 1;
	ft_putchar('\n');
	while (now <= l->i + l->ants)
	{
		i = 1;
		l->now_ant = now;
		while (i++ <= now)
		{
			if (l->now_ant <= l->ants && i < l->i)
				print_ant(l->now_ant--, l->route[i].name);
			else
				l->now_ant--;
		}
		ft_putchar('\n');
		now++;
	}
}
