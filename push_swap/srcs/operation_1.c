/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:50:37 by jiheo             #+#    #+#             */
/*   Updated: 2022/02/01 12:50:37 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operation.h"

void	sa(t_list *stack)
{
	swap_top_two_ele(stack, "sa\n");
}

void	sb(t_list *stack)
{
	swap_top_two_ele(stack, "sb\n");
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

int	pa(t_list *stack_a, t_list *stack_b)
{
	if (stack_b->len == 0)
		return (0);
	push_ele_to_dst_from_src(stack_a, stack_b, "pa\n");
	return (1);
}

int	pb(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->len == 0)
		return (0);
	push_ele_to_dst_from_src(stack_b, stack_a, "pb\n");
	return (1);
}
