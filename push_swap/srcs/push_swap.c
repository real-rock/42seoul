/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:50:46 by jiheo             #+#    #+#             */
/*   Updated: 2022/02/01 12:50:46 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_list *stack_a)
{
	const int	sorted = is_sorted(stack_a);
	t_list		*stack_b;

	stack_b = new_empty_list();
	if (!sorted && stack_a->len == 3)
		sort_three_elements(stack_a);
	else if (!sorted && stack_a->len == 4)
		sort_four_elements(stack_a, stack_b);
	else if (!sorted && stack_a->len == 5)
		sort_five_elements(stack_a, stack_b);
	else if (!sorted)
		move_a_to_b(stack_a, stack_b, stack_a->len);
	delete_list(stack_a);
	delete_list(stack_b);
}

void	undo_rotate(t_list *stack, int cnt, char *msg)
{
	while (cnt--)
		reverse_rotate_stack(stack, msg);
}

void	move_elements_a_to_b(t_list *stack_a, t_list *stack_b, int cnt)
{
	int	pivot;
	int	ra_count;
	int	pb_count;

	ra_count = 0;
	pb_count = 0;
	pivot = find_pivot(stack_a, cnt);
	while (cnt)
	{
		if (stack_a->tail->content > pivot)
			ra_count += ra(stack_a);
		else
			pb_count += pb(stack_a, stack_b);
		cnt--;
	}
	undo_rotate(stack_a, ra_count, "rra\n");
	move_a_to_b(stack_a, stack_b, ra_count);
	move_b_to_a(stack_a, stack_b, pb_count);
}

void	move_a_to_b(t_list *stack_a, t_list *stack_b, int cnt)
{
	if (cnt <= 1)
		return ;
	if (cnt == 2)
	{
		sort_two_elements(stack_a);
		return ;
	}
	if (is_sorted(stack_a))
		return ;
	move_elements_a_to_b(stack_a, stack_b, cnt);
}

void	move_b_to_a(t_list *stack_a, t_list *stack_b, int cnt)
{
	int	rb_count;
	int	pa_count;
	int	pivot;

	if (cnt == 0)
		return ;
	if (cnt == 1)
	{
		pa(stack_a, stack_b);
		return ;
	}
	pa_count = 0;
	rb_count = 0;
	pivot = find_pivot(stack_b, cnt);
	while (cnt)
	{
		if (stack_b->tail->content < pivot)
			rb_count += rb(stack_b);
		else
			pa_count += pa(stack_a, stack_b);
		cnt--;
	}
	undo_rotate(stack_b, rb_count, "rrb\n");
	move_a_to_b(stack_a, stack_b, pa_count);
	move_b_to_a(stack_a, stack_b, rb_count);
}
