/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:21:46 by jiheo             #+#    #+#             */
/*   Updated: 2022/01/10 15:45:25 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bit_field_8	convert_uchar_to_bit(unsigned char c)
{
	t_bit_field_8	c_bit;

	*(unsigned char *)&c_bit = c;
	return (c_bit);
}

unsigned char	convert_bit_to_uchar(t_bit_field_8 *bit_field)
{
	unsigned char	uchar;

	uchar = *(unsigned char *)bit_field;
	return (uchar);
}

void	print_bit_to_uchar(t_bit_field_8 *bit_field)
{
	const unsigned char	uchar = convert_bit_to_uchar(bit_field);

	write(1, &uchar, 1);
}
