/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sender.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:44:51 by jiheo             #+#    #+#             */
/*   Updated: 2022/01/09 15:48:01 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_signal(int bit, int pid)
{
	const int	sig = SIGUSR1 + bit;

	if (kill(pid, sig) == -1)
	{
		ft_putstr("Something went wrong!\n");
		exit(EXIT_FAILURE);
	}
	usleep(150);
}

static void	send_a_char(int c, int pid)
{
	const t_bit_field_8	bit_field = convert_uchar_to_bit((unsigned char)c);

	send_signal(bit_field.bit_1, pid);
	send_signal(bit_field.bit_2, pid);
	send_signal(bit_field.bit_3, pid);
	send_signal(bit_field.bit_4, pid);
	send_signal(bit_field.bit_5, pid);
	send_signal(bit_field.bit_6, pid);
	send_signal(bit_field.bit_7, pid);
	send_signal(bit_field.bit_8, pid);
}

void	send_a_string_with_null(const char *str, int pid)
{
	while (*str)
	{
		send_a_char(*str, pid);
		str++;
	}
	send_a_char('\n', pid);
	send_a_char('\0', pid);
}
