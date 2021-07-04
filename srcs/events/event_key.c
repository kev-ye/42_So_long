/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:24:21 by kaye              #+#    #+#             */
/*   Updated: 2021/07/04 21:10:48 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		event_key_press(int keycode)
{
	const int key[] = {KEY_CODE_W, KEY_CODE_S, KEY_CODE_A, KEY_CODE_D};
	int i;

	i = 0;
	if (keycode == KEY_CODE_ESC)
		__exit__(NULL, NULL, NOTHING);
	else
	{
		while (i < 4)
		{
			if (keycode == key[i] && singleton()->key_code[i] == 0)
				singleton()->key_code[i] = 1;
			++i;
		}
	}
	return (1);
}

int		event_key_release(int keycode)
{
	const int key[] = {KEY_CODE_W, KEY_CODE_S, KEY_CODE_A, KEY_CODE_D};
	int i;

	i = 0;
	if (keycode == KEY_CODE_ESC)
		__exit__(NULL, NULL, NOTHING);
	else
	{
		while (i < 4)
		{
			if (keycode == key[i] && singleton()->key_code[i] == 1)
				singleton()->key_code[i] = 0;
			++i;
		}
	}
	return (1);
}

int		event_key(void)
{
	// if (singleton()->key_code[e_W] == 1)
	// 	move_w(singleton());
	// if (singleton()->key_code[e_S] == 1)
	// 	move_s(singleton());
	// if (singleton()->key_code[e_A] == 1)
	// 	move_a(singleton());
	// if (singleton()->key_code[e_D] == 1)
	// 	move_d(singleton());
	return (1);
}

int		init_key(void)
{
	int i;

	i = 0;
	while (i < 4)
		singleton()->key_code[i++] = 0;
	return (1);
}