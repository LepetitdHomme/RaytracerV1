/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freesplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <camillesellier@live.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:25:29 by csellier          #+#    #+#             */
/*   Updated: 2017/04/07 14:28:32 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		freesplit(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return (1);
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	return (0);
}
