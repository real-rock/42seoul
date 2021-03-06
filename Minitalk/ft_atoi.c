/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:47:37 by jiheo             #+#    #+#             */
/*   Updated: 2022/01/07 14:53:16 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	is_space(const char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

static unsigned long long	str_to_dec(const char *str)
{
	unsigned long long	res;

	res = 0;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		res = *str - '0' + res * 10;
		str++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	number;

	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	number = str_to_dec(str);
	if (number > __LONG_LONG_MAX__)
	{
		if (sign > 0)
			return (-1);
		else
			return (0);
	}
	return (sign * (int)number);
}
