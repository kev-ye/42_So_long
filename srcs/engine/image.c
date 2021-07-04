/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:30:10 by kaye              #+#    #+#             */
/*   Updated: 2021/07/04 21:10:36 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*new_image(
		int size_width,
		int size_height)
{
	t_img *new_img;

	if (!(new_img = calloc(sizeof(t_img), 1)))
		__exit__(E_MALLOC, NULL, NOTHING);
	if (!(new_img->img_ptr = mlx_new_image(singleton()->mlx_ptr, size_width,
					size_height)))
		__exit__(E_MALLOC, NULL, NOTHING);
	new_img->addr = mlx_get_data_addr(new_img->img_ptr, &new_img->bpp,
			&new_img->line_len, &new_img->endian);
	new_img->width = size_width;
	new_img->height = size_height;
	return (new_img);
}