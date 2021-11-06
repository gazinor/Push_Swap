/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:17:11 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/20 23:42:02 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_n_instructions(t_int_list *a, t_int_list *b, int n, char *inst)
{
	while (n-- > 0)
		make_a_move(a, b, inst);
}

void	make_moves_from_rots2(t_int_list *a, t_int_list *b, int rotA, int rotB)
{
	if (rotA > 0)
		exec_n_instructions(a, b, rotA, "ra");
	else if (rotA < 0)
		exec_n_instructions(a, b, -rotA, "rra");
	if (rotB < 0)
		exec_n_instructions(a, b, -rotB, "rrb");
	else if (rotB > 0)
		exec_n_instructions(a, b, rotB, "rb");
}

void	make_moves_from_rots(t_int_list *a, t_int_list *b, int rotA, int rotB)
{
	are_rots_optimized(&rotA, get_list_length(b), &rotB);
	if (rotA < 0 && rotB < 0)
	{
		exec_n_instructions(a, b, smaller(-rotA, -rotB), "rrr");
		if (-rotA - -rotB > 0)
			exec_n_instructions(a, b, absolute(-rotA - -rotB), "rra");
		else
			exec_n_instructions(a, b, absolute(-rotA - -rotB), "rrb");
	}
	else if (rotA > 0 && rotB > 0)
	{
		exec_n_instructions(a, b, smaller(rotA, rotB), "rr");
		if (rotA - rotB > 0)
			exec_n_instructions(a, b, absolute(rotA - rotB), "ra");
		else
			exec_n_instructions(a, b, absolute(rotA - rotB), "rb");
	}
	else
		make_moves_from_rots2(a, b, rotA, rotB);
}
