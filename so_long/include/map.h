/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:40:27 by jiheo             #+#    #+#             */
/*   Updated: 2022/03/30 08:24:26 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include "types.h"
# include "errors.h"
# include "io.h"

t_map	*new_map(char *map_src);
void	count_map_info(t_map *map);
char	**map_malloc(int width, int height);
void	init_map(t_map *map, char *map_src);
void	rm_map(t_map *map);

#endif