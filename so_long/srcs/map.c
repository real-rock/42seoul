/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:43:02 by jiheo             #+#    #+#             */
/*   Updated: 2022/03/27 13:21:05 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"

t_map	*new_map(char *map_src)
{
	t_map	*m;

	m = (t_map *)malloc(sizeof(t_map));
	if (m == NULL)
		gen_err("new_map() failed with memory allocating\n");
	m->map = NULL;
	m->width = 0;
	m->height = 0;
	m->src = map_src;
	count_map_info(m);
	init_map(m, map_src);
	return (m);
}

char	**map_malloc(int width, int height)
{
	int		i;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * height);
	if (map == NULL)
		gen_err("error while allocating memory\n");
	while (i < height)
	{
		map[i] = (char *)malloc(sizeof(char) * width);
		if (map[i] == NULL)
			gen_err("error while allocating memory\n");
		i++;
	}
	return (map);
}

void	count_map_info(t_map *map)
{
	char	c;
	int		max_col;
	int		col;
	bool	is_first;

	col = 0;
	max_col = 0;
	is_first = true;
	map->fd = open_file(map->src);
	while (read(map->fd, &c, 1))
	{
		if (c == '\n')
		{
			if (!is_first && col != max_col)
				gen_err("Invalid map");
			is_first = false;
			max_col = col;
			col = 0;
			map->height++;
		}
		else
			col++;
	}
	map->width = max_col;
	close_file(map->fd);
}

void	init_map(t_map *map, char *map_src)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	map->map = map_malloc(map->width, map->height);
	map->fd = open_file(map->src);
	while (read(map->fd, &c, 1))
	{
		if (c == '\n')
		{
			i++;
			j = 0;
			continue ;
		}
		map->map[i][j++] = c;
	}
	close_file(map->fd);
}

void	rm_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->map[i++]);
	free(map->map);
}
