/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:41:29 by jiheo             #+#    #+#             */
/*   Updated: 2022/06/22 14:33:15 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static
void	init_philos(t_info *info)
{
	int	i;

	i = -1;
	info->philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (info->philos == NULL)
		exit_with_error("malloc error");
	while (++i < info->num_of_philo)
	{
		info->philos[i].info = info;
		info->philos[i].is_eating = 0;
		info->philos[i].position = i;
		info->philos[i].left_fork = i;
		info->philos[i].right_fork = (i + 1) % info->num_of_philo;
		info->philos[i].eat_count = 0;
	}
}

static
void	init_mutexes(t_info *info)
{
	int	i;

	pthread_mutex_init(&info->write_mutex, NULL);
	pthread_mutex_init(&info->life_mutex, NULL);
	pthread_mutex_lock(&info->life_mutex);
	info->fork_mutexes = \
		(pthread_mutex_t *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (info->fork_mutexes == NULL)
		exit_with_error("malloc error");
	i = -1;
	while (++i < info->num_of_philo)
	{
		pthread_mutex_init(&info->fork_mutexes[i], NULL);
		pthread_mutex_init(&info->philos[i].mutex, NULL);
		pthread_mutex_init(&info->philos[i].eat_m, NULL);
		pthread_mutex_lock(&info->philos[i].eat_m);
	}
}

t_info	*new_info(const int *int_argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (info == NULL)
		exit_with_error("malloc error");
	info->num_of_philo = int_argv[0];
	info->time_to_die = int_argv[1];
	info->time_to_eat = int_argv[2];
	info->time_to_sleep = int_argv[3];
	info->num_must_eat = int_argv[4];
	info->fork_mutexes = NULL;
	info->philos = NULL;
	init_philos(info);
	init_mutexes(info);
	return (info);
}
