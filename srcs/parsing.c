/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:38:44 by glaurent          #+#    #+#             */
/*   Updated: 2021/08/25 10:02:19 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_list(int val, t_int_list *root)
{
	t_int_list	*tmp;

	tmp = root->next;
	while (tmp != root && val > tmp->val)
		tmp = tmp->next;
	if (tmp->val == val)
		return (-1);
	add_tail(val, tmp);
	return (42);
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
