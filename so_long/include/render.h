/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:19:25 by jiheo             #+#    #+#             */
/*   Updated: 2022/03/29 10:37:24 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "types.h"
# include "errors.h"
# include "player.h"

void	render_tile(t_info *info);
void	render_wall(t_info *info);
void	render_ladder(t_info *info);
void	render_ball(t_info *info);

void	render_map_ele(t_info *info, int i, int j, t_map_ele me);
char	*get_render_src(t_map_ele me);
void	update_map(t_info *info);

void	update_player(t_info *info);

#endif