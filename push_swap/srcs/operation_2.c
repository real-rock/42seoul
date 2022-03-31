/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:50:40 by jiheo             #+#    #+#             */
/*   Updated: 2022/02/01 12:50:41 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operation.h"

int	ra(t_list *stack)
{
	rotate_stack(stack, "ra\n");
	return (1);
}

int	rb(t_list *stack)
{
	rotate_stack(stack, "rb\n");
	return (1);
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	rotate_stack(stack_a, "ra\n");
	rotate_stack(stack_b, "rb\n");
}
