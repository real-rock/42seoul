/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:54:18 by jiheo             #+#    #+#             */
/*   Updated: 2022/01/08 11:39:55 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_nbr(const long long n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		print_nbr(-n);
	}
	else if (n / 10 == 0)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		print_nbr(n / 10);
		c = n % 10 + '0';
		write(1, &c, 1);
	}
	return ;
}

void	ft_putnbr(const int n)
{
	print_nbr(n);
}
