/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_rots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:17:11 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/20 23:42:02 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rot_to_lowest_target(t_int_list *list, int target)
{
	t_int_list	*tmp;
	int			lowest;

	tmp = list->next;
	lowest = 1000000;
	while (tmp != list)
	{
		if (lowest > tmp->target_index && tmp->target_index < target)
			lowest = tmp->target_index;
		tmp = tmp->next;
	}
	return (lowest);
}

int	rot_to_highest_target(t_int_list *list, int target)
{
	t_int_list	*tmp;
	int			highest;

	tmp = list->next;
	highest = 0;
	while (tmp != list)
	{
		if (highest < tmp->target_index && tmp->target_index > target)
			highest = tmp->target_index;
		tmp = tmp->next;
	}
	return (highest);
}

int	highest_target(t_int_list *list, int target)
{
	t_int_list	*tmp;

	tmp = list->next;
	while (tmp != list)
	{
		if (tmp->target_index > target)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	lowest_target(t_int_list *list, int target)
{
	t_int_list	*tmp;

	tmp = list->next;
	while (tmp != list)
	{
		if (tmp->target_index < target)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
