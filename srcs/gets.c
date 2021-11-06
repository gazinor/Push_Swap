/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:17:11 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/20 23:42:02 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int_list	*get_elem(t_int_list *list, int index)
{
	t_int_list	*tmp;

	tmp = list->next;
	while (tmp != list)
	{
		if (tmp->index == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (list);
}

int	return_nb_of_rots(int lenb, int pos)
{
	if (pos <= lenb / 2)
		return (--pos);
	else
		return ((lenb - pos + 1) * -1);
}

int	get_nb_rot_rev_pos(t_int_list *list, int under_val)
{
	t_int_list	*tmp;
	int			val;
	int			pos;
	int			lenb;

	tmp = list->next;
	val = 1000000;
	pos = 1;
	lenb = 0;
	while (tmp != list)
	{
		if (tmp->target_index < val && tmp->target_index > under_val)
		{
			val = tmp->target_index;
			pos = tmp->index;
		}
		lenb = tmp->index;
		tmp = tmp->next;
	}
	if (lenb < 2)
		return (0);
	if (val == 1000000)
		return (get_nb_rot_rev_pos(list,
				rot_to_lowest_target(list, val) - 1));
	return (return_nb_of_rots(lenb, pos));
}

int	get_nb_rot_pos(t_int_list *list, int top_val)
{
	t_int_list	*tmp;
	int			val;
	int			pos;
	int			lenb;

	tmp = list->next;
	val = 0;
	pos = 1;
	lenb = 0;
	while (tmp != list)
	{
		if (tmp->target_index > val && tmp->target_index < top_val)
		{
			val = tmp->target_index;
			pos = tmp->index;
		}
		lenb = tmp->index;
		tmp = tmp->next;
	}
	if (lenb < 2 || top_val == 0)
		return (0);
	if (val == 0)
		return (get_nb_rot_pos(list,
				rot_to_highest_target(list, 1) + 1));
	return (return_nb_of_rots(lenb, pos));
}
