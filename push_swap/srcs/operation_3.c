/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:50:43 by jiheo             #+#    #+#             */
/*   Updated: 2022/02/01 12:50:43 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operation.h"

void	rra(t_list *stack)
{
	reverse_rotate_stack(stack, "rra\n");
}

void	rrb(t_list *stack)
{
	reverse_rotate_stack(stack, "rrb\n");
}

void	rrr(t_list *stack_a, t_list *stack_b)
{
	reverse_rotate_stack(stack_a, "rra\n");
	reverse_rotate_stack(stack_b, "rrb\n");
}
