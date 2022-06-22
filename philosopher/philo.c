/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:38:45 by jiheo             #+#    #+#             */
/*   Updated: 2022/06/22 13:56:47 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->is_eating = 1;
	philo->last_eat = get_time();
	philo->deadline = philo->last_eat + philo->info->time_to_die;
	write_msg(philo, EAT);
	usleep(philo->info->time_to_eat * 1000);
	philo->eat_count++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->eat_m);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork_mutexes[philo->left_fork]);
	write_msg(philo, FORK);
	pthread_mutex_lock(&philo->info->fork_mutexes[philo->right_fork]);
	write_msg(philo, FORK);
}

void	clean_forks_and_sleep(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->fork_mutexes[philo->left_fork]);
	pthread_mutex_unlock(&philo->info->fork_mutexes[philo->right_fork]);
	write_msg(philo, SLEEP);
	usleep(philo->info->time_to_sleep * 1000);
}
