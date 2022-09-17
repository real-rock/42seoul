/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:50:51 by jiheo             #+#    #+#             */
/*   Updated: 2022/02/01 12:50:52 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	simple_a_to_b(t_list *a, t_list *b, int max, int min)
{
	int	cnt;
	int	max_moved;
	int	min_moved;

	cnt = 5;
	max_moved = 0;
	min_moved = 0;
	while (cnt-- && !(max_moved && min_moved))
	{
		if (a->tail->content == max)
		{
			pb(a, b);
			max_moved = 1;
		}
		else if (a->tail->content == min)
		{
			pb(a, b);
			min_moved = 1;
		}
		else
			ra(a);
	}
}

void	simple_b_to_a(t_list *a, t_list *b, int max, int min)
{
	while (b->len != 0)
	{
		if (b->tail->content == max)
		{
			pa(a, b);
			ra(a);
		}
		else if (b->tail->content == min)
			pa(a, b);
	}
}

void	sort_five_elements(t_list *stack_a, t_list *stack_b)
{
	int	*arr;
	int	max;
	int	min;

	arr = conv_to_int_arr(stack_a, stack_a->len);
	max = find_max(arr, 5);
	min = find_min(arr, 5);
	free(arr);
	simple_a_to_b(stack_a, stack_b, max, min);
	sort_three_elements(stack_a);
	simple_b_to_a(stack_a, stack_b, max, min);
}
