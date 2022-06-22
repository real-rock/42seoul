/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:38:58 by jiheo             #+#    #+#             */
/*   Updated: 2022/06/22 14:33:04 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include "stdbool.h"

struct	s_philo;

typedef enum e_philo_state
{
	EAT,
	THINK,
	SLEEP,
	DEAD,
	DONE,
	FORK
}	t_philo_state;

typedef struct s_info
{
	int				num_of_philo;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				num_must_eat;
	struct s_philo	*philos;
	uint64_t		start_time;
	pthread_mutex_t	*fork_mutexes;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	life_mutex;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	int				position;
	int				is_eating;
	uint64_t		deadline;
	uint64_t		last_eat;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat_m;
}	t_philo;

t_info		*new_info(const int *int_argv);

void		exit_with_error(char *_msg);

void		write_msg(t_philo *philo, t_philo_state state);

void		eat(t_philo *philo);

void		take_forks(t_philo *philo);

void		clean_forks_and_sleep(t_philo *philo);

void		start_philo(t_info *info);

void		end_philo(t_info *info);

int			ft_atoi(const char *_s);

uint64_t	get_time(void);

#endif //PHILOSOPHER_H