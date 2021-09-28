/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:48:39 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/15 04:35:07 by glaurent         ###   ########.fr       */
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
		root->to_push = 0;
		root->prev = root;
		root->next = root;
	}
	return (root);
}

void	add_head(int val, t_int_list *root)
{
	t_int_list	*new;

	new = malloc(sizeof(*new));
	if (new != NULL)
	{
		new->val = val;
		new->to_push = 0;
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
		new->to_push = 0;
		new->prev = root->prev;
		new->next = root;
		root->prev->next = new;
		root->prev = new;
	}
}

int	get_list_length(t_int_list *a)
{
	t_int_list	*tmp;
	int			i;

	tmp = a->next;
	i = 0;
	while (tmp != a)
	{
		tmp = tmp->next;
		++i;
	}
	return (i);
}
