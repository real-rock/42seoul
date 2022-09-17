/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:57:30 by jiheo             #+#    #+#             */
/*   Updated: 2022/02/01 12:49:58 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "ft_errors.h"

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
}			t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		len;
}			t_list;

t_node	*new_node(int value);
void	delete_node(t_node *node);

t_list	*new_empty_list(void);
t_list	*new_list(int *data, int size);
void	delete_list(t_list *list);

void	list_push_back(t_list *list, int value);
void	list_push_front(t_list *list, int value);
int		list_pop_back(t_list *list);
int		list_pop_front(t_list *list);

void	list_rotate(t_list *list);
void	list_reverse_rotate(t_list *list);

#endif