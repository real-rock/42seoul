/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:13:24 by jiheo             #+#    #+#             */
/*   Updated: 2022/03/29 08:44:00 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/errors.h"

void	gen_err(char *msg)
{
	printf("[ERROR] Message: %s\n", msg);
	exit(EXIT_FAILURE);
}

void	gen_err_with_no(void)
{
	const char	*err_msg;

	err_msg = strerror(errno);
	printf("[ERROR] Message: %s\n", err_msg);
	exit(EXIT_FAILURE);
}
