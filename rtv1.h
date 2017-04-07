/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <camillesellier@live.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:32:29 by csellier          #+#    #+#             */
/*   Updated: 2017/04/07 15:43:04 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft/libft.h"
# include "X11/mlx.h"
# define ERROR "\033[0;31m"
# define WARNING "\033[1;31m"
# define USAGE "\033[1;33m"
# define END "\033[0;m"

#include <stdio.h>
#define DEBUG printf("%d / %s\n", __LINE__, __FILE__)

typedef struct		s_obj
{
	int				type;
	double			x;
	double			y;
	double			z;
	void			*data;
}					t_obj;

typedef struct		s_elem
{
	t_obj			*obj;
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_cam
{
	double			x;
	double			y;
	double			z;
	double			vx;
	double			vy;
	double			vz;
}					t_cam;

typedef struct		s_env
{
	int				scr_w;
	int				scr_h;
	t_cam			cam;
}					t_env;

int					error(int i);
int					get_camera_from_file(char **split);
int					get_objects_from_file(char **split);
int					get_screen_from_file(char **split);
t_env				*get_static_env(t_env *env);
int					parse(int ar, char **av);

#endif
