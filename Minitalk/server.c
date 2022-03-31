/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:35:39 by jiheo             #+#    #+#             */
/*   Updated: 2022/01/10 15:36:20 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	clean_message(t_message *message)
{
	message->bit_field.bit_1 = 0;
	message->bit_field.bit_2 = 0;
	message->bit_field.bit_3 = 0;
	message->bit_field.bit_4 = 0;
	message->bit_field.bit_5 = 0;
	message->bit_field.bit_6 = 0;
	message->bit_field.bit_7 = 0;
	message->bit_field.bit_8 = 0;
	message->index = 0;
}

void	set_bit_field(int bit, t_message *msg)
{
	if (msg->index == 1)
		msg->bit_field.bit_1 = bit;
	if (msg->index == 2)
		msg->bit_field.bit_2 = bit;
	if (msg->index == 3)
		msg->bit_field.bit_3 = bit;
	if (msg->index == 4)
		msg->bit_field.bit_4 = bit;
	if (msg->index == 5)
		msg->bit_field.bit_5 = bit;
	if (msg->index == 6)
		msg->bit_field.bit_6 = bit;
	if (msg->index == 7)
		msg->bit_field.bit_7 = bit;
	if (msg->index == 8)
		msg->bit_field.bit_8 = bit;
}

void	handle_signal(int signum, siginfo_t *siginfo, void *unsused)
{
	static t_message	msg;
	unsigned int		client_pid;

	(void)unsused;
	if (!msg.index)
		msg.index = 1;
	client_pid = siginfo->si_pid;
	set_bit_field(signum - SIGUSR1, &msg);
	if (msg.index == 8)
	{
		if (convert_bit_to_uchar(&(msg.bit_field)) == '\0')
			kill(client_pid, SIGUSR1);
		else
			print_bit_to_uchar(&(msg.bit_field));
		clean_message(&msg);
	}
	msg.index++;
}

void	print_pid(void)
{
	const int	pid = getpid();

	ft_putstr("PID: ");
	ft_putnbr(pid);
	ft_putstr("\n");
}

int	main(void)
{
	struct sigaction	sa;

	set_sa_server(&sa, handle_signal);
	print_pid();
	while (1)
		pause();
}
