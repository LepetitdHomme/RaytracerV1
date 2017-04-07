/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <camillesellier@live.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:01:31 by csellier          #+#    #+#             */
/*   Updated: 2017/04/07 15:46:13 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			get_screen_from_file(char **split)
{
	t_env	*env;
	char	**sub_split;

	if ((env = get_static_env(NULL)) == NULL || split == NULL)
		return (error(2));
	if (ft_tablen(split) < 2)
		return (error(3));
	if ((sub_split = ft_strsplit(split[1], ';')) == NULL)
		return (error(3));
	if (sub_split[0] != NULL && sub_split[1] != NULL)
	{
		if ((env->scr_w = ft_atoi(sub_split[0])) < 10 && error(50))
			env->scr_w = 200;
		if ((env->scr_h = ft_atoi(sub_split[1])) < 10 && error(50))
			env->scr_h = 200;
	}
	else
		return (error(3));
	freesplit(sub_split);
	free(sub_split);
	return(0);
}

static int	get_camera2(t_env *env, char **split)
{
	char	**sub_split;

	if ((sub_split = ft_strsplit(split[2], ';')) == NULL ||
	ft_tablen(sub_split) < 3)
		return (error(3));
	if (sub_split[0] != NULL && sub_split[1] != NULL && sub_split[2] != NULL)
	{
		env->cam.vx = ft_atoi(sub_split[0]);
		env->cam.vy = ft_atoi(sub_split[1]);
		env->cam.vz = ft_atoi(sub_split[2]);
		freesplit(sub_split);
		free(sub_split);
	}
	else
		return (error(3));
	return (0);
}

int			get_camera_from_file(char **split)
{
	t_env	*env;
	char	**sub_split;

	if ((env = get_static_env(NULL)) == NULL || split == NULL)
		return (error(2));
	if (ft_tablen(split) < 3)
		return (error(3));
	if ((sub_split = ft_strsplit(split[1], ';')) == NULL ||
	ft_tablen(sub_split) < 3)
		return (error(3));
	if (sub_split[0] != NULL && sub_split[1] != NULL && sub_split[2] != NULL)
	{
		env->cam.x = ft_atoi(sub_split[0]);
		env->cam.y = ft_atoi(sub_split[1]);
		env->cam.z = ft_atoi(sub_split[2]);
		freesplit(sub_split);
		free(sub_split);
	}
	else
		return (error(3));
	return (get_camera2(env, split));
}
