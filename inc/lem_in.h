/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:06:24 by odushko           #+#    #+#             */
/*   Updated: 2019/07/27 14:06:26 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/inc/get_next_line.h"
# define INTMAX 2147483647
# define COMMENT 1
# define COMMAND 2
# define RED "\033[0;31m"
# define NC "\033[0m"
# define YELLOW "\033[1;33m"

typedef struct		s_room
{
	char			*name;
	int				visited;
	struct s_room	*prev;
	struct s_link	*links;
}					t_room;

typedef struct		s_link
{
	t_room			room;
	struct s_link	*next;
}					t_link;

typedef struct		s_lem
{
	t_room			*r;
	t_room			*queue;
	t_room			*route;
	char			**file;
	char			*file_tmp;
	int				path_size;
	int				fd;
	int				ants;
	int				rnum;
	int				i;
	int				j;
	int				num;
	int				q;
	int				q2;
	int				now_ant;
}					t_lem;

int					is_room(char *line);
int					is_comment(const char *line);
int					is_link(char *line);
void				error(t_lem *l, int er_num);
int					room_pos(const char *name, t_lem *l);

void				handle_rooms(t_lem *l);
void				handle_links(t_lem *l);
int					bfs(t_lem *l);
int					create_a_route(t_lem *l);
void				ants_route(t_lem *l);
int					get_input(t_lem *l);

#endif
