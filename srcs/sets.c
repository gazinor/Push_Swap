/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 05:38:29 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/29 05:38:30 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_to_push_values(t_int_list *root, int begining, int precision)
{
	t_int_list	*tmp;
	t_int_list	*copy;
	int			t_i;

	tmp = root->next;
	while (--begining > 0)
		tmp = tmp->next;
	t_i = tmp->target_index;
	tmp->to_push = 0;
	copy = tmp->next;
	while (copy != tmp)
	{
		if (copy == root)
			copy = copy->next;
		if (copy->target_index > t_i && copy->target_index <= t_i + precision)
		{
			copy->to_push = 0;
			t_i = copy->target_index;
		}
		else
			copy->to_push = 1;
		if (copy != tmp)
			copy = copy->next;
	}
}

void	set_indexes(t_int_list *root)
{
	int			index;
	t_int_list	*tmp;

	index = 0;
	tmp = root->next;
	while (tmp != root)
	{
		tmp->index = ++index;
		tmp = tmp->next;
	}
}

void	set_target_indexes(t_int_list *root, t_int_list *sorted_list)
{
	t_int_list	*tmp_root;
	t_int_list	*tmp_sorted_list;
	int			index;

	tmp_root = root->next;
	while (tmp_root != root)
	{
		index = 1;
		tmp_sorted_list = sorted_list->next;
		while (tmp_sorted_list != sorted_list)
		{
			if (tmp_root->val == tmp_sorted_list->val)
			{
				tmp_root->target_index = index;
				break ;
			}
			tmp_sorted_list = tmp_sorted_list->next;
			++index;
		}
		tmp_root = tmp_root->next;
	}
	set_indexes(root);
}

void	set_find_loop(t_find_loop **fl, t_int_list *list, int precision)
{
	if (*fl == NULL)
	{
		*fl = &((t_find_loop){.count = 0, .max_target = list->target_index,
				.loop_index = 0, .max_count = 0});
	}
	if (precision == 1)
		(*fl)->max_count = 0;
	(*fl)->count = 0;
	(*fl)->max_target = list->target_index;
}
