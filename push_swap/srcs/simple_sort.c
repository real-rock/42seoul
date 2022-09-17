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

void	sort_two_elements(t_list *stack)
{
	t_node	*tail;

	tail = stack->tail;
	if (tail->content > tail->prev->content)
		swap_top_two_ele(stack, "sa\n");
}

void	sort_three_elements(t_list *stack)
{
	int	*arr;

	arr = conv_to_int_arr(stack, stack->len);
	if (arr[0] < arr[2] && arr[2] < arr[1])
		ft_putstr_fd("rra\nsa\n", 1);
	else if (arr[1] < arr[0] && arr[0] < arr[2])
		ft_putstr_fd("sa\n", 1);
	else if (arr[1] < arr[2] && arr[2] < arr[0])
		ft_putstr_fd("ra\n", 1);
	else if (arr[2] < arr[0] && arr[0] < arr[1])
		ft_putstr_fd("rra\n", 1);
	else if (arr[2] < arr[1] && arr[1] < arr[0])
		ft_putstr_fd("sa\nrra\n", 1);
	free(arr);
}

void	sort_four_elements(t_list *a, t_list *b)
{
	int	*arr;
	int	min;
	int	cnt;

	arr = conv_to_int_arr(a, a->len);
	min = find_min(arr, 4);
	free(arr);
	cnt = 4;
	while (cnt--)
	{
		if (a->tail->content == min)
		{
			pb(a, b);
			break ;
		}
		ra(a);
	}
	sort_three_elements(a);
	pa(a, b);
}
