/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:42:11 by jiheo             #+#    #+#             */
/*   Updated: 2022/06/23 09:58:59 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static
void	*monitor_count(void *_info_in)
{
	t_info	*info;
	int		i;
	int		total;

	info = (t_info *)_info_in;
	total = 0;
	while (info->num_must_eat == -1 || total < info->num_must_eat)
	{
		i = 0;
		while (i < info->num_of_philo)
			pthread_mutex_lock(&info->philos[i++].eat_m);
		total++;
	}
	write_msg(&info->philos[0], DONE);
	pthread_mutex_unlock(&info->life_mutex);
	return ((void *)0);
}

static
void	*monitor(void *_philo_in)
{
	t_philo		*philo;

	philo = (t_philo *)_philo_in;
	while (true)
	{
		pthread_mutex_lock(&philo->mutex);
		if (!philo->is_eating && get_time() > philo->deadline)
		{
			write_msg(philo, DEAD);
			pthread_mutex_unlock(&philo->mutex);
			pthread_mutex_unlock(&philo->info->life_mutex);
			return ((void *)0);
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(1000);
	}
}

static
void	*process(void *_philo_in)
{
	t_philo		*philo;
	pthread_t	monitor_thread;
	int			err;

	philo = (t_philo *)_philo_in;
	philo->last_eat = get_time();
	philo->deadline = philo->last_eat + philo->info->time_to_die;
	err = pthread_create(&monitor_thread, NULL, &monitor, _philo_in);
	if (err != 0)
		exit_with_error("Failed to create philo monitor");
	pthread_detach(monitor_thread);
	while (true)
	{
		take_forks(philo);
		eat(philo);
		clean_forks_and_sleep(philo);
		write_msg(philo, THINK);
	}
}

void	start_philo(t_info *_info)
{
	int			i;
	pthread_t	thread;
	int			err;

	_info->start_time = get_time();
	if (_info->num_must_eat < -1)
		return ;
	err = pthread_create(&thread, NULL, &monitor_count, (void *)_info);
	if (err != 0)
		exit_with_error("Failed to create philo");
	pthread_detach(thread);
	i = -1;
	while (++i < _info->num_of_philo)
	{
		err = pthread_create(&thread, NULL, \
			&process, (void *)(&_info->philos[i]));
		if (err != 0)
			exit_with_error("Failed to create routine");
		pthread_detach(thread);
		usleep(100);
	}
}
