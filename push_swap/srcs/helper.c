/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:50:31 by jiheo             #+#    #+#             */
/*   Updated: 2022/02/01 12:50:32 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*conv_to_int_arr(t_list *stack, int cnt)
{
	int		*arr;
	t_node	*ele;
	int		idx;

	arr = (int *)malloc(cnt * sizeof(int));
	idx = 0;
	ele = stack->tail;
	while (ele != NULL && idx < cnt)
	{
		arr[idx++] = ele->content;
		ele = ele->prev;
	}
	return (arr);
}

int	find_pivot(t_list *stack, int cnt)
{
	int		*arr;
	int		piv;

	arr = conv_to_int_arr(stack, cnt);
	quick_sort(arr, 0, cnt - 1);
	piv = arr[(cnt - 1) / 2];
	free(arr);
	return (piv);
}

int	is_sorted(t_list *stack)
{
	t_node	*ele;
	int		prev_val;

	ele = stack->head;
	prev_val = ele->content;
	ele = ele->next;
	while (ele != NULL)
	{
		if (ele->content > prev_val)
			return (0);
		prev_val = ele->content;
		ele = ele->next;
	}
	return (1);
}

int	find_max(int *arr, int size)
{
	int	max;

	max = arr[size - 1];
	while (size--)
	{
		if (arr[size] > max)
			max = arr[size];
	}
	return (max);
}

int	find_min(int *arr, int size)
{
	int	min;

	min = arr[size - 1];
	while (size--)
	{
		if (arr[size] < min)
			min = arr[size];
	}
	return (min);
}
