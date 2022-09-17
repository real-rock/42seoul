/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_adv_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:50:08 by jiheo             #+#    #+#             */
/*   Updated: 2022/02/01 12:50:09 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/list.h"

void	list_rotate(t_list *list)
{
	int	back;

	if (list->len < 2)
		return ;
	back = list_pop_back(list);
	list_push_front(list, back);
}

void	list_reverse_rotate(t_list *list)
{
	int	front;

	if (list->len < 2)
		return ;
	front = list_pop_front(list);
	list_push_back(list, front);
}
