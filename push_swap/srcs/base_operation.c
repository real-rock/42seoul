/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:50:27 by jiheo             #+#    #+#             */
/*   Updated: 2022/02/01 12:50:27 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operation.h"

void	swap_tail_head(t_list *stack)
{
	t_node	*head;
	t_node	*tail;

	head = stack->head;
	tail = stack->tail;
	head->prev = tail;
	head->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	stack->head = tail;
	stack->tail = head;
}

void	swap_top_two_ele(t_list *stack, char *msg)
{
	t_node	*top;
	t_node	*below_top;

	if (stack->len < 2)
		return ;
	ft_putstr_fd(msg, 1);
	if (stack->len == 2)
	{
		swap_tail_head(stack);
		return ;
	}
	top = stack->tail;
	below_top = top->prev;
	below_top->prev->next = top;
	top->prev = below_top->prev;
	top->next = below_top;
	below_top->prev = top;
	below_top->next = NULL;
	stack->tail = below_top;
}

void	push_ele_to_dst_from_src(t_list *dst, t_list *src, char *msg)
{
	if (src->len == 0)
		return ;
	ft_putstr_fd(msg, 1);
	list_push_back(dst, list_pop_back(src));
}

void	rotate_stack(t_list *stack, char *msg)
{
	ft_putstr_fd(msg, 1);
	list_rotate(stack);
}

void	reverse_rotate_stack(t_list *stack, char *msg)
{
	ft_putstr_fd(msg, 1);
	list_reverse_rotate(stack);
}
