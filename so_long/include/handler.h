/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:48:42 by jiheo             #+#    #+#             */
/*   Updated: 2022/03/27 13:42:41 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_H
# define HANDLER_H

# include <stdlib.h>
# include "types.h"
# include "player.h"

int		close_window(t_info *info);
int		key_handler(int keycode, t_info *info);
void	key_pressed_handler(t_info *info, int keycode);
int		key_released_handler(int keycode, t_info *info);

#endif