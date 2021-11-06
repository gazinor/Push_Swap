/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_before_instruction.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:17:11 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/20 23:42:02 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_list_circular_sorted(t_int_list *a, t_int_list *b,
							int *rot, t_instruction_list **l)
{
	if (check_if_sorted_v2(a, SMALL_TO_BIG) > 0)
	{
		if (b->next == b)
		{
			if (*rot < 0)
				while (*rot++ != 0)
					make_a_move(a, b, "rra");
			else if (*rot > 0)
				while (*rot-- != 0)
					make_a_move(a, b, "ra");
		}
		else
		{
			push_all_to_a(a, b, l);
			return (-1);
		}
	}
	return (0);
}

int	checks_before_instruction(t_instruction_list **l, t_int_list *a,
		t_int_list *b)
{
	int	rot;

	rot = get_nb_rot_pos(a, 2);
	if (lowest_target(a, a->next->target_index) == 1)
		if (is_list_circular_sorted(a, b, &rot, l) == -1)
			return (-1);
	if (check_if_sorted(a, SMALL_TO_BIG) == 1
		&& check_if_sorted(b, BIG_TO_SMALL))
	{
		push_all_to_a(a, b, l);
		return (-1);
	}
	if (get_list_length(a) > 9
		&& a->next->target_index == a->next->next->target_index + 1)
		make_a_move(a, b, "sa");
	return (1);
}
