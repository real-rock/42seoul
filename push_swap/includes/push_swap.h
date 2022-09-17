/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:50:03 by jiheo             #+#    #+#             */
/*   Updated: 2022/02/01 12:51:08 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "operation.h"

void	push_swap(t_list *stack_a);
void	sort_two_elements(t_list *stack);
void	sort_three_elements(t_list *stack);
void	sort_four_elements(t_list *a, t_list *b);
void	sort_five_elements(t_list *stack_a, t_list *stack_b);

int		find_max(int *arr, int size);
int		find_min(int *arr, int size);

void	undo_rotate(t_list *stack, int cnt, char *msg);
void	swap(int *a, int *b);
void	quick_sort(int *arr, int start, int end);
int		is_sorted(t_list *stack);
int		*conv_to_int_arr(t_list *stack, int cnt);
int		find_pivot(t_list *stack, int cnt);
void	move_a_to_b(t_list *stack_a, t_list *stack_b, int cnt);
void	move_b_to_a(t_list *stack_a, t_list *stack_b, int cnt);

#endif