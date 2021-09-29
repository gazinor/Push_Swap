/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:17:11 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/29 06:05:22 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_shortest_rots_alignement(int keep_rot, int keep_index, int *shortest)
{
	if (keep_rot * keep_index >= 0 && bigger(absolute(keep_rot),
			absolute(keep_index)) < *shortest)
	{
		*shortest = bigger(absolute(keep_rot), absolute(keep_index));
		return (1);
	}
	else if (keep_rot * keep_index < 0
		&& absolute(keep_rot) + absolute(keep_index) < *shortest)
	{
		*shortest = absolute(keep_rot) + absolute(keep_index);
		return (2);
	}
	return (-1);
}

void	set_shortest_alignment(int *ra, int *rb, t_int_list *a, t_int_list *b)
{
	t_int_list	*tmp;
	int			shortest;
	int			keep_rot;
	int			keep_index;
	int			lenb;

	tmp = b->next;
	shortest = 1000000;
	lenb = get_list_length(b);
	while (tmp != b)
	{
		keep_rot = get_nb_rot_rev_pos(a, tmp->target_index);
		keep_index = tmp->index - 1;
		are_rots_optimized(&keep_rot, lenb, &keep_index);
		if (set_shortest_rots_alignement(keep_rot, keep_index, &shortest) != -1)
		{
			*ra = keep_rot;
			*rb = keep_index;
		}
		tmp = tmp->next;
	}
}

void	push_all_to_a(t_int_list *a, t_int_list *b, t_instruction_list **l)
{
	t_int_list	*t_b;
	int			ra;
	int			rb;

	t_b = b->next;
	erase_instructions(l);
	ra = 0;
	rb = 0;
	while (b->next != b)
	{
		set_shortest_alignment(&ra, &rb, a, b);
		make_moves_from_rots(a, b, ra, rb);
		make_a_move(a, b, "pa");
		t_b = t_b->next;
	}
}
