/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:50:22 by jiheo             #+#    #+#             */
/*   Updated: 2022/02/01 12:50:23 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/list.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->content = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	delete_node(t_node *node)
{
	if (node == NULL)
		generate_error("Error");
	node->next = NULL;
	node->prev = NULL;
	free(node);
	node = NULL;
	return ;
}

t_list	*new_empty_list(void)
{
	t_list	*list;

	list = (t_list *) malloc(sizeof(t_list));
	if (list == NULL)
		exit(EXIT_FAILURE);
	list->len = 0;
	list->tail = NULL;
	list->head = NULL;
	return (list);
}

t_list	*new_list(int *data, int size)
{
	t_list	*list;
	int		idx;

	list = new_empty_list();
	idx = 0;
	while (idx < size)
		list_push_back(list, data[idx++]);
	return (list);
}

void	delete_list(t_list *list)
{
	t_node	*target;
	t_node	*next;

	if (list == NULL)
		generate_error("Error");
	target = list->head;
	while (target != NULL)
	{
		next = target->next;
		delete_node(target);
		target = next;
	}
	free(list);
}
