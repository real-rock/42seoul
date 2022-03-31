/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:13:36 by jiheo             #+#    #+#             */
/*   Updated: 2022/03/30 08:36:13 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "types.h"
# include "map.h"
# include "errors.h"
# include "utils.h"
# include "coordinate.h"
# include "player.h"
# include "handler.h"
# include "render.h"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

void	init_game(t_info *info, char *src);
void	check_and_exit_game(t_info *info);

#endif