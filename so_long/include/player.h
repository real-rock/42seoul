/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:49:01 by jiheo             #+#    #+#             */
/*   Updated: 2022/03/29 09:29:50 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <stdio.h>
# include "types.h"
# include "coordinate.h"

t_coordinate	get_player_coord(t_info *info);
void			move_player(t_info *info, t_direction dir);
void			turn_player(t_info *info, t_direction dir);

#endif