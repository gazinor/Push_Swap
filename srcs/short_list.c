/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:17:11 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/20 23:42:02 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ideal_instructions(t_int_list *a, t_instruction_list **l)
{
	int	e1;
	int	e2;
	int	e3;

	e1 = get_elem(a, 1)->target_index;
	e2 = get_elem(a, 2)->target_index;
	e3 = get_elem(a, 3)->target_index;
	if (e1 > e2)
	{
		if (e3 > e1 || e3 < e2)
			instruction_append(l, "sa");
		else if (e3 > e2 && e3 < e1)
			instruction_append(l, "ra");
		if (e3 < e2)
			instruction_append(l, "rra");
	}
	else if (e1 < e2)
	{
		instruction_append(l, "rra");
		if (e3 > e1)
			instruction_append(l, "sa");
	}
}
