/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:01:42 by jiheo             #+#    #+#             */
/*   Updated: 2022/05/30 21:39:41 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_info	*new_info(int *int_argv)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (info == NULL)
		gen_error("Malloc failed");
	info->num_of_philo = int_argv[0];
	info->time_to_die = int_argv[1];
	info->time_to_eat = int_argv[2];
	info->time_to_sleep = int_argv[3];
	info->min_count_to_eat = int_argv[4];
	printf("num_of_philo: %d\n", int_argv[0]);
	printf("time_to_die: %d\n", int_argv[1]);
	printf("time_to_eat: %d\n", int_argv[2]);
	printf("time_to_sleep: %d\n", int_argv[3]);
	printf("min_count_to_eat: %d\n", int_argv[4]);
	return (info);
}

t_info	*check_arg(int argc, char **argv)
{
	int		i;
	int		res[5];

	i = 0;
	res[4] = -1;
	while (++i < argc)
		res[i] = ft_atoi(argv[i]);
	return (new_info(res));
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 5 && argc != 6)
		gen_error("Invalid argument");
	check_arg(argc, argv);
	info = check_arg(argc, argv);
}
