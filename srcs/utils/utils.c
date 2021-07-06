/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:19:39 by kaye              #+#    #+#             */
/*   Updated: 2021/07/05 19:59:02 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	__free__(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	__singleton_clean__(void)
{
	int	i;

	if (singleton()->mlx_ptr)
	{
		if (singleton()->img)
		{
			mlx_destroy_image(singleton()->mlx_ptr, singleton()->img->img_ptr);
			__free__(singleton()->img);
		}
		i = 0;
		while (i < TEX_NBR)
			mlx_destroy_image(singleton()->mlx_ptr, singleton()->tex[i++].img_ptr);
		mlx_destroy_window(singleton()->mlx_ptr, singleton()->win_ptr);
		mlx_destroy_display(singleton()->mlx_ptr);
		free(singleton()->mlx_ptr);
	}
	i = 0;
	if (singleton()->map)
	{
		while (singleton()->map[i])
			__free__(singleton()->map[i++]);
		__free__(singleton()->map[i]);
		__free__(singleton()->map);
	}
	__free__((void *)singleton());
}

int	__exit__(char *msg, void *ptr, int fd, int ret)
{
	if (msg)
	{
		if (ret == FAILURE)
			ft_putstr("Error\n");
		ft_printf("%s\n", msg);
	}
	if (ptr)
		__free__(ptr);
	if (fd != NOTHING)
		close(fd);
	if (singleton())
		__singleton_clean__();
	exit(ret);
}

int	__open__(char *path, const int flag)
{
	const int	fd = open(path, flag);

	if (!fd)
		__exit__(strerror(errno), NULL, NOTHING, FAILURE);
	return ((int)fd);
}

t_win	*singleton(void)
{
	static t_win	*philo = NULL;

	if (!philo)
	{
		philo = ft_calloc(sizeof(t_win), 1);
		if (!philo)
			exit(FAILURE);
	}
	return (philo);
}
