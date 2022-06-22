/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:41:21 by jiheo             #+#    #+#             */
/*   Updated: 2022/06/22 10:41:23 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static
void	clear_mutexes(t_info *info)
{
	int	i;

	if (info->fork_mutexes)
	{
		i = -1;
		while (++i < info->num_of_philo)
			pthread_mutex_destroy(&info->fork_mutexes[i]);
		free(info->fork_mutexes);
	}
	if (info->philos)
	{
		i = -1;
		while (++i < info->num_of_philo)
		{
			pthread_mutex_destroy(&info->philos[i].mutex);
			pthread_mutex_destroy(&info->philos[i].eat_m);
		}
		free(info->philos);
	}
	pthread_mutex_destroy(&info->write_mutex);
	pthread_mutex_destroy(&info->life_mutex);
}

void	end_philo(t_info *info)
{
	clear_mutexes(info);
	free(info);
	info = NULL;
}
