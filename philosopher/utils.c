/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:43:37 by jiheo             #+#    #+#             */
/*   Updated: 2022/06/22 10:51:28 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atoi(const char *_s)
{
	long long	res;

	res = 0;
	while (*_s)
	{
		if (*_s < '0' || *_s > '9')
			exit_with_error("Invalid argument value");
		res *= 10;
		res += (long long)(*_s - '0');
		if (res > INT_MAX)
			exit_with_error("Invalid argument value");
		_s++;
	}
	return ((int)res);
}

uint64_t	get_time(void)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (uint64_t)1000) + (time.tv_usec / 1000));
}
