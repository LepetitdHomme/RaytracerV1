#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: csellier <camillesellier@live.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/04/07 12:45:02 by csellier          #+#    #+#             *#
#*   Updated: 2017/04/07 16:53:59 by csellier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = rtv1

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC =   error.c\
		get_file_data.c\
		get_file_objects.c\
		keys.c\
		main.c\
		parse.c\
		static.c

INC = rtv1.h struct.h

OBJ = $(SRC:.c=.o)

$(NAME) : $(INC) $(OBJ)
	make -C libft/
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) -L libft/ -L X11 -lmlx -lft -lXext -lX11 -lm

all : $(NAME)

%.o : %.c $(INC)
	$(CC) $(FLAGS) -I. -c $<

clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	make -C libft/ fclean
	rm -rf $(NAME)

re : fclean all
