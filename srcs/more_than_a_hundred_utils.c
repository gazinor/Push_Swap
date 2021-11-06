/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_a_hundred_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:17:11 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/20 23:42:02 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_how_many_to_keep(t_int_list *list)
{
	t_int_list	*tmp;
	int			count;

	tmp = list->next;
	count = 0;
	while (tmp != list)
	{
		if (tmp->index == 0)
			tmp = tmp->next;
		if (tmp->to_push == 0)
			++count;
		if (tmp != list)
			tmp = tmp->next;
	}
	return (count);
}

int	is_swap_needed(t_int_list *list, t_find_loop loop)
{
	int	hmtk;
	int	loop_index;

	if (loop.loop_index == 1)
		loop_index = 2;
	else
		loop_index = loop.loop_index;
	hmtk = get_how_many_to_keep(list);
	swap(list);
	set_to_push_values(list, loop_index, loop.precision);
	if (hmtk < get_how_many_to_keep(list))
		ft_putstr_fd("sa", 1);
	else
	{
		swap(list);
		set_to_push_values(list, loop.loop_index, loop.precision);
		return (0);
	}
	return (1);
}

void	actualize_find_loop_values(t_find_loop **fl,
		t_int_list *list, int precision)
{
	if ((*fl)->count > (*fl)->max_count)
	{
		(*fl)->max_count = (*fl)->count;
		(*fl)->loop_index = list->index;
		(*fl)->precision = precision;
	}
}
