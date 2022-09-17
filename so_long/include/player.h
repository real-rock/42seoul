/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:49:01 by jiheo             #+#    #+#             */
/*   Updated: 2022/05/16 11:31:18 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <stdio.h>
# include "types.h"
# include "coordinate.h"
# include "so_long.h"

void			move_player(t_info *info, t_direction dir);
void			turn_player(t_info *info, t_direction dir);

#endif