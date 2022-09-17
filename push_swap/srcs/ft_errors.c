/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:50:29 by jiheo             #+#    #+#             */
/*   Updated: 2022/02/01 12:50:30 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_errors.h"

void	generate_error(char *msg)
{
	ft_putstr_fd(msg, 1);
	exit(EXIT_FAILURE);
}
