/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:48:00 by jiheo             #+#    #+#             */
/*   Updated: 2022/01/10 15:34:55 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_putstr("Connection has been succeed!\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_putstr("Connection failed!\n");
		exit(EXIT_FAILURE);
	}
}

int	get_pid_from_argv(const char *pid_str)
{
	int	pid;

	pid = ft_atoi(pid_str);
	if (pid < 100 || pid >= 99999)
	{
		ft_putstr("Invalid pid!\n");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	check_argument(int argc)
{
	if (argc != 3)
	{
		ft_putstr("Wrong arguments!\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	check_argument(argc);
	pid = get_pid_from_argv(argv[1]);
	set_sa_client(&sa, handle_signal);
	send_a_string_with_null(argv[2], pid);
	while (1)
		pause();
}
