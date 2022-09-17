/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:37:30 by jiheo             #+#    #+#             */
/*   Updated: 2022/04/29 18:00:56 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATE_H
# define COORDINATE_H
# include "types.h"
# include "errors.h"

void	set_coord(t_coordinate *co, int row, int col);
void	to_right(t_map *map, t_player *player);
void	to_left(t_map *map, t_player *player);
void	to_up(t_map *map, t_player *player);
void	to_down(t_map *map, t_player *player);

#endif