# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odushko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/28 10:36:07 by odushko           #+#    #+#              #
#    Updated: 2019/07/15 16:55:38 by odushko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C := gcc

NAME := lem-in

FLAGS := -Wall -Werror -Wextra -O2

LIBFT := libft

HEADER := inc

SOURCES := src/lem_in.c
SOURCES += src/get_input.c
SOURCES += src/handle_input.c
SOURCES += src/tools.c
SOURCES += src/bfs.c
SOURCES += src/ants_route.c

OBJS = $(SOURCES:.c=.o)

RED =\033[0;31m
LRED =\033[1;31m
ORANGE =\033[0;33m
YELLOW =\033[1;33m
LGREEN =\033[1;32m
GREEN =\033[0;32m
BLUE =\033[1;34m
VIOLET =\033[1;35m

NC =\033[0m

all: $(NAME)
	@echo "$(LGREEN)\nLem_in is done!\n$(NC)"

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@gcc -o $(NAME) $(FLAGS) $(OBJS) $(LIBFT)/libft.a

norm:
	norminette $(SOURCES)

clean:
	@echo "$(YELLOW)Deleting the object files.$(NC)"
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@echo "$(YELLOW)Deleting the executable file.\n$(NC)"
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
