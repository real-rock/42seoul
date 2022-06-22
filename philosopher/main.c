/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:01:42 by jiheo             #+#    #+#             */
/*   Updated: 2022/06/22 14:34:34 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_info	*check_arg_and_init_info(int argc, char **argv)
{
	int		i;
	int		res[5];

	i = 0;
	res[4] = -1;
	while (++i < argc)
	{
		res[i - 1] = ft_atoi(argv[i]);
		if (res[i - 1] < 0)
			exit_with_error("bad arguments");
	}
	return (new_info(res));
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 5 && argc != 6)
		exit_with_error("Invalid argument");
	info = check_arg_and_init_info(argc, argv);
	start_philo(info);
	pthread_mutex_lock(&info->life_mutex);
	pthread_mutex_unlock(&info->life_mutex);
	end_philo(info);
}
