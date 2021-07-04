/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:34:15 by kaye              #+#    #+#             */
/*   Updated: 2021/07/04 21:09:28 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void init(char *path)
{
	if (!(singleton()->mlx_ptr = mlx_init()))
		__exit__(E_MALLOC, NULL, NOTHING);
	if (!(singleton()->img = new_image(singleton()->width, singleton()->height)))
        __exit__(E_MALLOC, NULL, NOTHING);
    singleton()->width = 480;
    singleton()->height = 480;
    init_key();
}

static void check_ac(int ac)
{
	int save;

	if (ac < 2)
		__exit__("Too few arguments", NULL, NOTHING);
	if (ac > 2)
		__exit__("Too much arguments", NULL, NOTHING);
}

int				main(int ac, char **av)
{
	check_ac(ac);
    check_map_file(av[1]);
    init(av[1]);
    parsing(av[1]);
	// mlx_hook(singleton()->win_ptr, 2, 1L << 0, event_key_press, singleton());
	// mlx_hook(singleton()->win_ptr, 3, 1L << 1, event_key_release, singleton());
	// mlx_hook(singleton()->win_ptr, RED_CROSS, 1L << 2, event_destroy_win, singleton());
	// mlx_loop_hook(singleton()->mlx_ptr, event_loop, singleton());
	// mlx_loop(singleton()->mlx_ptr);
	return (SUCCESS);
}