/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:39:25 by jiheo             #+#    #+#             */
/*   Updated: 2021/12/02 11:07:44 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		res = *str - '0' + res * 10;
		str++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	number;

	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	number = (long long)str_to_dec(str) * sign;
	if (number > INT_MAX || number < INT_MIN)
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	return ((int)number);
}
