/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <camillesellier@live.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:41:28 by csellier          #+#    #+#             */
/*   Updated: 2017/04/07 15:47:02 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		get_object(char **split, int *scr, int *cam)
{
	if (split == NULL)
		return (1);
	if (split[0] && ft_strncmp(split[0], "screen", 6) == 0)
	{
		if (get_screen_from_file(split) != 0)
			return (1);
		*scr = 1;
	}
	else if (split[0] && ft_strncmp(split[0], "camera", 6) == 0)
	{
		if (get_camera_from_file(split) != 0)
			return (1);
		*cam = 1;
	}
	else
		if (split[0] && get_objects_from_file(split) != 0)
			return (1);
	return (0);
}

static int		get_data_from_file(int fd, int *scr, int *cam)
{
	t_env	*env;
	char	*buf;
	char	**split;

	if ((env = get_static_env(NULL)) == NULL)
		return (error(2));
	while (get_next_line(fd, &buf) == 1)
	{
		if ((split = ft_strsplit(buf, '|')) == NULL)
			return (error(3));
		if (get_object(split, scr, cam) != 0)
		{
			freesplit(split);
			free(split);
			return (1);
		}
		freesplit(split);
		free(split);
		free(buf);
	}
	return (0);
}

int				parse(int ar, char **av)
{
	int		fd;
	int		scr;
	int		cam;

	if (ar < 2 || av[1] == NULL)
		return (error(0));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (error(1));
	cam = 0;
	scr= 0;
	if (get_data_from_file(fd, &scr, &cam) != 0 || cam != 1 || scr != 1)
	{
		if (scr != 1)
			error(5);
		else if (scr == 1 && cam != 1)
			error(4);
		close(fd);
		return (1);
	}
	close(fd);
	printf("%d / %d\n", get_static_env(NULL)->scr_w, get_static_env(NULL)->scr_h);
	return (0);
}
