/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:50:01 by jiheo             #+#    #+#             */
/*   Updated: 2022/02/01 12:50:01 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H
# include "list.h"

void	swap_top_two_ele(t_list *stack, char *msg);
void	push_ele_to_dst_from_src(t_list *stack_a, t_list *stack_b, char *msg);
void	rotate_stack(t_list *stack, char *msg);
void	reverse_rotate_stack(t_list *stack, char *msg);

void	sa(t_list *stack);
void	sb(t_list *stack);
void	ss(t_list *stack_a, t_list *stack_b);
int		pa(t_list *stack_a, t_list *stack_b);
int		pb(t_list *stack_a, t_list *stack_b);
int		ra(t_list *stack);
int		rb(t_list *stack);
void	rr(t_list *stack_a, t_list *stack_b);
void	rra(t_list *stack);
void	rrb(t_list *stack);
void	rrr(t_list *stack_a, t_list *stack_b);

#endif