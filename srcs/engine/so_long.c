/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:04:39 by kaye              #+#    #+#             */
/*   Updated: 2021/07/04 19:10:45 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void		draw_pix(t_win *win, int map_x, int map_y, unsigned int color)
// {
// 	int x;
// 	int y;

// 	x = 0;
// 	while (x < win->pix_size)
// 	{
// 		y = 0;
// 		while (y < win->pix_size)
// 		{
// 			pixel_put_color(win->mini_map, x + map_x, y + map_y, color);
// 			y++;
// 		}
// 		x++;
// 	}
// }

// static	void	draw_mini_map(t_win *win, int x, int y)
// {
// 	if (win->desc_info->map[y / win->pix_size][x / win->pix_size] == '1')
// 		draw_pix(win, x, y, WHITE);
// 	else if (win->desc_info->map[y / win->pix_size][x / win->pix_size] == '2')
// 		draw_pix(win, x, y, BLUE);
// 	else if (win->desc_info->map[y / win->pix_size][x / win->pix_size] == '3')
// 		draw_pix(win, x, y, YELLOW);
// 	else if (win->desc_info->map[y / win->pix_size][x / win->pix_size] == '4')
// 		draw_pix(win, x, y, RED);
// 	else if ((y / win->pix_size) == (int)win->camera->pos_y
// 			&& (x / win->pix_size) == (int)win->camera->pos_x)
// 		draw_pix(win, x, y, WHITE);
// 	else
// 		draw_pix(win, x, y, 0xFF000000);
// }

// int				init_mini_map(t_win *win)
// {
// 	int size_x;
// 	int size_y;

// 	size_x = win->pix_size * win->desc_info->map_x;
// 	size_y = win->pix_size * win->desc_info->map_y;
// 	if (size_x > win->width || size_y > win->height ||
// 			size_x == 0 || size_y == 0)
// 		return (1);
// 	if (!(win->mini_map = new_image(win, size_x, size_y)))
// 		return (0);
// 	return (1);
// }

// void			mini_map(t_win *win)
// {
// 	int x;
// 	int y;

// 	x = 0;
// 	while (x / win->pix_size < win->desc_info->map_x)
// 	{
// 		y = 0;
// 		while (y / win->pix_size < win->desc_info->map_y)
// 		{
// 			draw_mini_map(win, x, y);
// 			y += win->pix_size;
// 		}
// 		x += win->pix_size;
// 	}
// 	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->mini_map->img_ptr,
// 			win->width - (win->pix_size * win->desc_info->map_x), 0);
// }