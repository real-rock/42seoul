/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:50:34 by jiheo             #+#    #+#             */
/*   Updated: 2022/02/01 12:50:35 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_argv(char **argv)
{
	int	idx;

	idx = 0;
	while (argv[idx] != NULL)
		idx++;
	return (idx);
}

void	check_duplicated(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				ft_putstr_fd("Error\n", 1);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	*argv_to_int_arr(int argc, char **argv)
{
	int	*data;
	int	idx;

	data = (int *)malloc((argc - 1) * sizeof(int));
	idx = argc - 1;
	while (idx > 0)
	{
		data[argc - idx - 1] = ft_atoi(argv[idx]);
		idx--;
	}
	check_duplicated(data, argc - 1);
	return (data);
}

int	*envs_to_int_arr(int *argc, char **argv)
{
	int	*data;
	int	idx;

	argv = ft_split(argv[1], ' ');
	*argc = count_argv(argv);
	data = (int *)malloc((*argc) * sizeof(int));
	idx = *argc - 1;
	while (idx >= 0)
	{
		data[*argc - idx - 1] = ft_atoi(argv[idx]);
		idx--;
	}
	return (data);
}

int	main(int argc, char **argv)
{
	t_list	*stack;
	int		*data;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		data = envs_to_int_arr(&argc, argv);
		stack = new_list(data, argc);
	}
	else
	{
		data = argv_to_int_arr(argc, argv);
		stack = new_list(data, argc - 1);
	}
	free(data);
	push_swap(stack);
	exit(EXIT_SUCCESS);
}
