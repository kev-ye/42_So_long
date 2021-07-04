/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:19:39 by kaye              #+#    #+#             */
/*   Updated: 2021/07/04 21:11:16 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void __free__(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

int	__exit__(char *msg, void *ptr, int fd)
{
	if (msg)
		ft_printf("Error\n%s\n", msg);
	if (ptr)
		__free__(ptr);
	if (fd != NOTHING)
		close(fd);
	if (singleton())
    {
        // mlx_destroy_window(singleton()->mlx_ptr, singleton()->win_ptr);
		if (singleton()->img)
			__free__(singleton()->img);
        __free__((void *)singleton());
    }
    exit(FAILURE);
}

int	__open__(char *path, const int flag)
{
	const int fd = open(path, flag);

	if (!fd)
		__exit__(strerror(errno), NULL, NOTHING);
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