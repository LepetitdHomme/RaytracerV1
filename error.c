/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <camillesellier@live.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:37:15 by csellier          #+#    #+#             */
/*   Updated: 2017/04/07 16:47:47 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	usage(int i)
{
	ft_putstr_fd(USAGE, 2);
	if (i == 0)
		ft_putendl_fd("usage : 'screen | Xsize;Ysize'", 2);
	if (i == 1)
		ft_putendl_fd("usage : camera | 0x;0y;0z | DirX;DirY;DirZ", 2);
	ft_putstr_fd(END, 2);
	return (0);
}

static int	warning(int i)
{
	ft_putstr_fd(WARNING, 2);
	if (i == 50)
		ft_putendl_fd("file warning : size too small ; resized", 2);
	ft_putstr_fd(END, 2);
	return (0);
}

static int	error2(int i)
{
	ft_putstr_fd(ERROR, 2);
	if (i == 6)
		ft_putendl_fd("error : mlx_init() failed", 2);
	if (i == 7)
		ft_putendl_fd("error : mlx_new_window() failed", 2);
	ft_putstr_fd(END, 2);
	return (1);
}

int			error(int i)
{
	ft_putstr_fd(ERROR, 2);
	if (i == 0)
		ft_putendl_fd("error : this programm needs argument", 2);
	if (i == 1)
		ft_putendl_fd("error: could not open file", 2);
	if (i == 2)
		ft_putendl_fd("error : static env lost", 2);
	if (i == 3)
		ft_putendl_fd("error : file seems not well formated", 2);
	if (i == 4)
	{
		ft_putendl_fd("file error : missing camera or camera wrong format", 2);
		usage(1);
	}
	if (i == 5)
	{
		ft_putendl_fd("file error : missing screen or screen wrong format", 2);
		usage(0);
	}
	if (i >= 50)
		warning(i);
	ft_putstr_fd(END, 2);
	return (error2(i));
}
