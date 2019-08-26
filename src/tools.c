/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:06:08 by odushko           #+#    #+#             */
/*   Updated: 2019/07/27 14:06:10 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int			is_link(char *line)
{
	int		i;

	i = -1;
	if (ft_strlen(line) < 1)
		return (-1);
	if (line[0] == '#')
		return (0);
	while (line[++i] != '\0')
		if (line[i] == ' ')
			return (0);
	return (1);
}

int			is_comment(const char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (COMMENT);
	return (line[0] == '#' && line[1] == '#' ? COMMAND : 0);
}

int			is_room(char *line)
{
	int		i;
	int		space;
	int		num;

	i = -1;
	if (ft_strlen(line) < 1 || line[0] == '#')
		return (0);
	space = 0;
	num = 0;
	while (line[++i] != '\0')
	{
		if (line[i] == ' ')
		{
			space++;
			if (line[i + 1] - '0' > -1 && line[i + 1] - '0' < 10)
				num++;
		}
	}
	if (space == 2 && num == 2)
		return (1);
	return (0);
}

int			room_pos(const char *name, t_lem *l)
{
	int		i;

	i = -1;
	while (++i < l->rnum)
		if (!ft_strcmp(name, l->r[i].name))
			return (i);
	return (-1);
}

void		error(t_lem *l, int er_num)
{
	ft_putstr(RED);
	ft_putendl("ERROR");
	ft_putstr(YELLOW);
	er_num == 0 ? ft_putendl("Wrong ant number.") : 0;
	er_num == 1 ? ft_putendl("There's no end or start.") : 0;
	er_num == 2 ? ft_putendl("There's no room with this name.") : 0;
	er_num == 3 ? ft_putendl("There's no tube to end room.") : 0;
	er_num == 4 ? ft_putendl("Ugh, empty line!") : 0;
	ft_putstr(NC);
	system("leaks -q lem-in");
	exit(1);
}
