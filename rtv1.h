/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <camillesellier@live.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:32:29 by csellier          #+#    #+#             */
/*   Updated: 2017/04/07 17:34:59 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft/libft.h"
# include "X11/mlx.h"
# include "struct.h"


# define ESC 65307

# define ERROR "\033[0;31m"
# define WARNING "\033[1;31m"
# define USAGE "\033[1;33m"
# define END "\033[0;m"

#include <stdio.h>
#define DEBUG printf("%d / %s\n", __LINE__, __FILE__)

int					error(int i);
int					get_camera_from_file(char **split);
int					get_objects_from_file(char **split);
int					get_screen_from_file(char **split);
t_env				*get_static_env(t_env *env);
int					key_pressed(int key, t_env *env);
int					parse(int ar, char **av);
int					quit(int key, t_env *env);

#endif
