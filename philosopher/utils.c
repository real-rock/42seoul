/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:43:37 by jiheo             #+#    #+#             */
/*   Updated: 2022/05/30 21:26:28 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atoi(char *_s)
{
	long long	res;

	res = 0;
	while (*_s)
	{
		if (*_s < '0' || *_s > '9')
			gen_error("Invalid argument value");
		res *= 10;
		res += (long long)(*_s - '0');
		if (res > INT_MAX)
			gen_error("Invalid argument value");
		_s++;
	}
	return ((int)res);
}
