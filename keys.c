/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <camillesellier@live.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 16:52:54 by csellier          #+#    #+#             */
/*   Updated: 2017/04/07 16:58:47 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		quit(int key, t_env *env)
{
	(void)key;
	(void)env;
	exit(EXIT_SUCCESS);
}

int		key_pressed(int key, t_env *env)
{
	printf("%d = key\n", key);
	if (key == ESC)
		quit(key, env);
	return (0);
}
