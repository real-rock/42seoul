/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:47:51 by jiheo             #+#    #+#             */
/*   Updated: 2022/01/10 15:16:06 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	set_sa_client(struct sigaction *sa, t_sa_handler handler)
{
	sa->sa_flags = SA_RESTART;
	sa->sa_handler = handler;
	sigaction(SIGUSR1, sa, NULL);
	sigaction(SIGUSR2, sa, NULL);
}

void	set_sa_server(struct sigaction *sa, t_sa_sigaction handler)
{
	sa->sa_flags = SA_SIGINFO;
	sa->sa_sigaction = handler;
	sigaction(SIGUSR1, sa, NULL);
	sigaction(SIGUSR2, sa, NULL);
}
