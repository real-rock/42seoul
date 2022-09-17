/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_base_operator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:50:15 by jiheo             #+#    #+#             */
/*   Updated: 2022/02/01 12:50:16 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/list.h"

void	push_to_empty_list(t_list *list, int value)
{
	t_node	*node;

	node = new_node(value);
	list->head = node;
	list->tail = node;
	list->len = 1;
}

void	list_push_back(t_list *list, int value)
{
	t_node	*node;

	if (list->len == 0)
		push_to_empty_list(list, value);
	else
	{
		node = new_node(value);
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
		list->len += 1;
	}
}

void	list_push_front(t_list *list, int value)
{
	t_node	*node;

	if (list->len == 0)
		push_to_empty_list(list, value);
	else
	{
		node = new_node(value);
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
		list->len += 1;
	}
}

int	list_pop_back(t_list *list)
{
	t_node	*tail;
	int		tail_value;

	if (list->len == 0)
		generate_error("Can't pop from empty list");
	if (list->len == 1)
	{
		tail_value = list->tail->content;
		list->len = 0;
		delete_node(list->head);
		list->head = NULL;
		list->tail = NULL;
		return (tail_value);
	}
	tail = list->tail;
	tail_value = tail->content;
	list->tail = tail->prev;
	list->tail->next = NULL;
	list->len -= 1;
	delete_node(tail);
	return (tail_value);
}

int	list_pop_front(t_list *list)
{
	t_node	*head;
	int		head_value;

	if (list->len == 0)
		generate_error("Can't pop from empty list");
	if (list->len == 1)
	{
		head_value = list->head->content;
		delete_node(list->head);
		list->head = NULL;
		list->tail = NULL;
		return (head_value);
	}
	head = list->head;
	head_value = head->content;
	list->head = head->next;
	list->head->prev = NULL;
	list->len -= 1;
	delete_node(head);
	return (head_value);
}
