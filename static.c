/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <camillesellier@live.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:44:15 by csellier          #+#    #+#             */
/*   Updated: 2017/04/07 13:45:12 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_env	*get_static_env(t_env *env)
{
	static t_env	*old = NULL;

	if (env != NULL)
		old = env;
	return (old);
}
