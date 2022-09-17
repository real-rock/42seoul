/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:20:29 by jiheo             #+#    #+#             */
/*   Updated: 2022/03/29 10:35:55 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

void	update_map(t_info *info)
{
	render_tile(info);
	render_wall(info);
	render_ladder(info);
	render_ball(info);
}
