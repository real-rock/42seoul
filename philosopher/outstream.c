/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outstream.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:46:27 by jiheo             #+#    #+#             */
/*   Updated: 2022/06/22 14:04:32 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	exit_with_error(char *_msg)
{
	if (_msg == 0 || *_msg == 0)
		printf("Error\n");
	else
		printf("Error > %s\n", _msg);
	exit(EXIT_FAILURE);
}

static
void	_write_state_msg(t_philo_state state)
{
	if (state == EAT)
		printf(" is eating\n");
	else if (state == SLEEP)
		printf(" is sleeping\n");
	else if (state == THINK)
		printf(" is thinking\n");
	else if (state == FORK)
		printf(" has taken a fork\n");
	else if (state == DONE)
		printf("Philosophers finished eating\n");
	else
		printf(" died\n");
}

void	write_msg(t_philo *philo, t_philo_state state)
{
	static int	done = 0;

	pthread_mutex_lock(&philo->info->write_mutex);
	if (!done)
	{
		printf("%llu ", get_time() - philo->info->start_time);
		if (state != DONE)
			printf("%d", philo->position + 1);
		if (state == DEAD || state == DONE)
			done = 1;
		_write_state_msg(state);
	}
	pthread_mutex_unlock(&philo->info->write_mutex);
}
