/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:09:09 by kaye              #+#    #+#             */
/*   Updated: 2021/07/04 21:10:13 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_parser
{
	int		fd;
	int		ret;
	char	*line;
	int		len;
	int		tmp_len;
	int		i;
}	t_parser;

enum	e_count
{
	collectible,
	map_exit,
	player
};

void	check_map_file(char *path)
{
	char	*tmp;
	int		fd;

	tmp = ft_strrchr(path, '.');
	if (!tmp || ft_strcmp(tmp, ".ber"))
		__exit__("File format no correct", NULL, NOTHING);
	fd = open(path, O_RDWR);
	if (fd == -1)
		__exit__(strerror(errno), NULL, NOTHING);
	close(fd);
}

int	wall_check(char *line, int len, int index, int ret)
{
	int	i;

	i = 0;
	if (index == 0 || ret == 0)
	{
		while (line && line[i])
		{
			if (line[i++] != '1')
				return (0);
		}
	}
	else
	{
		if (line[0] != '1' || line[len - 1] != '1')
			return (0);
	}
	return (1);
}

int	least_character_check(char *line, int ret)
{
	static int	cnt[3] = {0};
	const char	c[] = {'C', 'E', 'P'};
	int			i;
	int			j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (j < 3)
		{
			if (line[i] == c[j])
				++cnt[j];
			++j;
		}
		++i;
	}
	i = 0;
	if (!ret)
	{
		while (i < 3)
			if (cnt[i++] < 1 || cnt[2] > 1)
				return (0);
	}
	return (1);
}

int	line_check(char *line)
{
	const char	map_c[] = {'0', '1', 'C', 'E', 'P'};
	int			i;
	int			j;

	i = 0;
	while (line && line[i])
	{
		j = 0;
		while (j < 5)
		{
			if (line[i] == map_c[j])
				break ;
			++j;
		}
		if (j == 5)
			return (0);
		++i;
	}
	return (1);
}

void	parsing(char *path)
{
	t_parser	p;

	ft_bzero(&p, sizeof(t_parser));
	p.fd = __open(path, O_RDONLY);
	p.ret = 1;
	p.len = -1;
	while (p.ret)
	{
		p.tmp_len = p.len;
		p.ret = get_next_line(p.fd, &p.line);
		p.len = ft_strlen(p.line);
		if (p.tmp_len != -1 && p.tmp_len != p.len)
			__exit__("Map no correct", p.line, p.fd);
		if (!line_check(p.line) || !wall_check(p.line, p.len, p.i, p.ret)
			|| !least_character_check(p.line, p.ret) || !*p.line)
			__exit__("Map no correct", p.line, p.fd);
		free(p.line);
		++p.i;
	}
	close(p.fd);
}
