/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 05:39:18 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/29 05:39:18 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_a_move_part2(t_int_list *a, t_int_list *b, char *move)
{
	if (!str_compare(move, "ra"))
		rotate(a, 0);
	else if (!str_compare(move, "rb"))
		rotate(b, 0);
	else if (!str_compare(move, "rr"))
	{
		rotate(a, 0);
		rotate(b, 0);
	}
	else if (!str_compare(move, "rra"))
		rotate(a, 1);
	else if (!str_compare(move, "rrb"))
		rotate(b, 1);
	else if (!str_compare(move, "rrr"))
	{
		rotate(a, 1);
		rotate(b, 1);
	}
	else
	{
		free_list(&a);
		free_list(&b);
		free(move);
		print_error();
	}
}

void	make_a_move_no_print(t_int_list *a, t_int_list *b, char *move)
{
	if (!str_compare(move, "pa"))
		push(b, a);
	else if (!str_compare(move, "pb"))
		push(a, b);
	else if (!str_compare(move, "sa"))
		swap(a);
	else if (!str_compare(move, "sb"))
		swap(b);
	else if (!str_compare(move, "ss"))
	{
		swap(a);
		swap(b);
	}
	else
		make_a_move_part2(a, b, move);
}

void	make_a_move(t_int_list *a, t_int_list *b, char *move)
{
	if (!str_compare(move, "pa"))
		push(b, a);
	else if (!str_compare(move, "pb"))
		push(a, b);
	else if (!str_compare(move, "sa"))
		swap(a);
	else if (!str_compare(move, "sb"))
		swap(b);
	else if (!str_compare(move, "ss"))
	{
		swap(a);
		swap(b);
	}
	else
		make_a_move_part2(a, b, move);
	ft_putstr_fd(move, 1);
}
