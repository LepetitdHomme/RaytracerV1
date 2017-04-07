/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <camillesellier@live.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 16:38:35 by csellier          #+#    #+#             */
/*   Updated: 2017/04/07 16:43:03 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	void			*scr;
	void			*win;
	void			*img;
	int				scr_w;
	int				scr_h;
	t_cam			cam;
}					t_env;

#endif
