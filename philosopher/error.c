/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:46:27 by jiheo             #+#    #+#             */
/*   Updated: 2022/05/30 21:26:30 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	gen_error(char *_msg)
{
	if (_msg == 0 || *_msg == 0)
		printf("Error\n");
	else
		printf("Error > %s\n", _msg);
	exit(EXIT_FAILURE);
}
