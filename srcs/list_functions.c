/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:48:39 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/12 19:40:40 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int_list	*create_list(void)
{
	t_int_list	*root;

	root = malloc(sizeof(*root));
	if (root != NULL)
	{
		root->val = 1111999;
		root->index = 0;
		root->target_index = 0;
		root->prev = root;
		root->next = root;
	}
	return (root);
}

void	empty_list(t_int_list *list)
{
	t_int_list	*tmp;
	t_int_list	*next;

	tmp = list->next;
	while (tmp != list)
	{
		next = tmp->next;
		if (tmp)
			free(tmp);
		tmp = next;
	}
}

void	remove_elem(t_int_list *elem)
{
	elem->prev->next = elem->next;
	elem->next->prev = elem->prev;
	if (elem)
		free(elem);
	elem = NULL;
}

void	add_head(int val, t_int_list *root)
{
	t_int_list	*new;

	new = malloc(sizeof(*new));
	if (new != NULL)
	{
		new->val = val;
		new->prev = root;
		new->next = root->next;
		root->next->prev = new;
		root->next = new;
	}
}

void	add_tail(int val, t_int_list *root)
{
	t_int_list	*new;

	new = malloc(sizeof(*new));
	if (new != NULL)
	{
		new->val = val;
		new->prev = root->prev;
		new->next = root;
		root->prev->next = new;
		root->prev = new;
	}
}
