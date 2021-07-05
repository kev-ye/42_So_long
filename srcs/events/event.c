/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:19:18 by kaye              #+#    #+#             */
/*   Updated: 2021/07/05 20:28:40 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bonus_hud(void)
{
	const char	*str = ft_itoa(singleton()->player.count);

	if (!str)
		__exit__(E_MALLOC, NULL, NOTHING, FAILURE);
	mlx_string_put(singleton()->mlx_ptr,
		singleton()->win_ptr,
		0,
		0,
		0xFFFFFF,
		"Movement count : ");
	mlx_string_put(singleton()->mlx_ptr,
		singleton()->win_ptr,
		170,
		0,
		0xFFFFFF,
		(char *)str);
	__free__((char *)str);
}

int	event_loop(void)
{
	so_long();
	bonus_hud();	
	event_key();
	return (1);
}

int	event_destroy_win(void)
{
	__exit__(NULL, NULL, NOTHING, SUCCESS);
	return (1);
}
