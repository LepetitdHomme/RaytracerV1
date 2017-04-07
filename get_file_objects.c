/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <camillesellier@live.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 15:00:12 by csellier          #+#    #+#             */
/*   Updated: 2017/04/07 15:17:08 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_objects_from_file(char **split)
{
	t_env	*env;

	if ((env = get_static_env(NULL)) == NULL || split == NULL)
		return (error(2));
	return (0);
}
