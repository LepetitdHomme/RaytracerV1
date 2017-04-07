#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: csellier <camillesellier@live.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/04/07 12:45:02 by csellier          #+#    #+#             *#
#*   Updated: 2017/04/07 15:51:23 by csellier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = rtv1

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC =   error.c\
		get_file_data.c\
		get_file_objects.c\
		main.c\
		parse.c\
		static.c

INC = rtv1.h

OBJ = $(SRC:.c=.o)

$(NAME) : $(INC) $(OBJ)
	make -C libft/
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) -L libft/ -lft

all : $(NAME)

%.o : %.c rtv1.h
	$(CC) $(FLAGS) -I. -c $<

clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	make -C libft/ fclean
	rm -rf $(NAME)

re : fclean all
