//
// Created by Jinseok Heo on 2022/06/02.
//

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include "stdbool.h"

struct	s_philo;

typedef struct s_info
{
	int				num_of_philo;
	uint16_t		time_to_die;
	uint16_t		time_to_eat;
	uint16_t		time_to_sleep;
	int				min_count_to_eat;

	bool			start;

	struct s_philo	*philos;
	pthread_mutex_t	*forks_m;
	pthread_mutex_t	write_m;
	pthread_mutex_t	somebody_dead_m;
}		t_info;

typedef struct s_philo
{
	t_info			*info;
	int				position;
	int				is_eating;
	uint16_t		limit;
	uint16_t		last_eat;
	int				lfork;
	int				rfork;
	int				eat_count;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat_m;
}		t_philo;

void	gen_error(char *_msg);
int		ft_atoi(char *_s);

#endif //PHILOSOPHER_H
