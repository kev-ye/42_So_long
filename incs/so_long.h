/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:51:12 by kaye              #+#    #+#             */
/*   Updated: 2021/07/04 21:09:04 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <mlx.h>
# include "libft.h"

/* KEY CODE MACOS / LINUX */
# if defined (__APPLE__) && (__MACH__)
#  define KEY_CODE_ESC 53
#  define KEY_CODE_W 13
#  define KEY_CODE_S 1
#  define KEY_CODE_A 0
#  define KEY_CODE_D 2
#  define RED_CROSS 17
# else
#  define KEY_CODE_ESC 65307
#  define KEY_CODE_W 119
#  define KEY_CODE_S 115
#  define KEY_CODE_A 97
#  define KEY_CODE_D 100
#  define RED_CROSS 33
# endif

/* SHELL PRINT CODE */
# define S_NONE "\033[0m"
# define S_BLACK "\033[0;30m"
# define S_RED "\033[0;31m"
# define S_GREEN "\033[0;32m"
# define S_YELLOW "\033[0;33m"
# define S_BLUE "\033[0;34m"
# define S_PURPLE "\033[0;35m"
# define S_CYAN "\033[0;36m"
# define S_CLRLINE "\033[K\r"

/* EXIT CODE */
# define SUCCESS 0
# define FAILURE 1
# define NOTHING -1

/* ERROR MSG */
# define E_MALLOC "Malloc/mlx error"

/*
** STRUCT - IMAGE
**
** Bpp      : The number of bits per pixels.
** Line_len : The size of a line.
** Endian   : Endian.
*/
typedef struct	s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}   t_img;

/*
** STRUCT - EVENT KEY
*/
// typedef struct	s_key
// {
// 	int		key_w;
// 	int		key_s;
// 	int		key_a;
// 	int		key_d;
// }   t_key;
enum    s_key
{
	e_W,
	e_S,
	e_A,
	e_D
};

/*
** STRUCT - GLOBAL
*/
typedef struct	s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	int         key_code[4];
	char		**map;
	t_img		*img;
}   t_win;

/* ENGINE */
t_img	*new_image(int size_width, int size_height);

/* EVENTS */
int		event_loop(void);
int		event_destroy_win(t_win *win);
int		event_key_press(int keycode);
int		event_key_release(int keycode);
int		event_key(void);
int		init_key(void);

/* PARSER */
void	check_map_file(char *path);
void	parsing(char *path);

/* UTILS */
void    __free__(void *ptr);
int		__exit__(char *msg, void *ptr, int fd);
int		__open__(char *path, const int flag);
t_win   *singleton(void);

#endif