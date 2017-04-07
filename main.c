/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <camillesellier@live.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:34:01 by csellier          #+#    #+#             */
/*   Updated: 2017/04/07 17:35:03 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		init_mlx(t_env *e)
{
	if (e == NULL)
		return (1);
	if ((e->scr = mlx_init()) == NULL)
		return (error(6));
	if ((e->win = mlx_new_window(e->scr, e->scr_w, e->scr_h, "RTv1")) == NULL)
		return (error(7));
	return (0);
}

static t_env	*init_env(void)
{
	t_env	*env;

	if ((env = (t_env *)malloc(sizeof(t_env))) == NULL)
		return (NULL);
	env->scr_w = 200;
	env->scr_h = 200;
	env->cam.x = 0;
	env->cam.y = 0;
	env->cam.z = 0;
	env->cam.vx = 1;
	env->cam.vy = 1;
	env->cam.vz = 1;
	get_static_env(env);
	return (env);
}

int				main(int ar, char **av)
{
	t_env	*env;

	if ((env = init_env()) == NULL)
		return (1);
	if (parse(ar, av) != 0)
		return (1);
	if (init_mlx(env) != 0)
		return (1);
	mlx_hook(env->win, 2, 1L << 0, key_pressed, env);
	mlx_hook(env->win, 17, 1, quit, env);
	mlx_loop(env->scr);
	return (0);
}
