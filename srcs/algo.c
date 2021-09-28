/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:26:53 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/20 20:46:07 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	are_rots_optimized(int *rotA, int lenB, int *rotB)
{
	if (*rotA * *rotB < 0)
	{
		if (*rotB < 0)
		{
			if (*rotA - *rotB > bigger(*rotA, lenB + *rotB))
				*rotB = lenB + *rotB;
		}
		else
			if (*rotB - *rotA > bigger(-*rotA,
					absolute(-lenB + *rotB)))
				*rotB = -lenB + *rotB;
	}
}

int	find_ranged_target_index(t_int_list *a, int min, int max, int len)
{
	t_int_list	*tmp;
	t_int_list	*rev_tmp;
	int			count;
	int			len_manager;

	tmp = a->next;
	rev_tmp = a->prev;
	count = 0;
	len_manager = len;
	while (tmp != a && rev_tmp != a)
	{
		++count;
		if (tmp->target_index >= min && tmp->target_index <= max)
			return (count);
		if (rev_tmp->target_index >= min && rev_tmp->target_index <= max)
			return (len_manager);
		--len_manager;
		tmp = tmp->next;
		rev_tmp = rev_tmp->prev;
	}
	if (len >= 15 && len < 100)
		return (find_ranged_target_index(a, max, max + len / 5, len));
	else if (len >= 100)
		return (find_ranged_target_index(a, max, max + len / 11, len));
	return (find_ranged_target_index(a, max, max + 1, len));
}

int	how_many_rotates(t_int_list *a, int len)
{
	int	hmrotates;
	int	max;

	if (len >= 2 && len < 15)
		max = 1;
	else if (len >= 15 && len <= 200)
		max = len / 5;
	else if (len > 200)
		max = len / 11;
	else
		return (0);
	hmrotates = find_ranged_target_index(a, 1, max, len);
	if (hmrotates <= ((int)(len / 2)))
		return (hmrotates - 1);
	else
		return ((len - hmrotates + 1) * -1);
}

void	set_instruction_list(t_instruction_list **l, t_int_list *a,
		t_int_list *b)
{
	int	rotatesa;
	int	rotatesb;
	int	lena;

	lena = get_list_length(a);
	if (lena >= 100)
	{
		long_list_algo(l, a, b);
		return ;
	}
	rotatesa = how_many_rotates(a, lena);
	if (rotatesa < 0)
		rotatesb = get_nb_rot_pos(b,
				get_elem(a, lena + rotatesa + 1)->target_index);
	else if (rotatesa > 0)
		rotatesb = get_nb_rot_pos(b,
				get_elem(a, rotatesa + 1)->target_index);
	else
		rotatesb = get_nb_rot_pos(b, get_elem(a, 1)->target_index);
	are_rots_optimized(&rotatesa, get_list_length(b), &rotatesb);
	if (lena == 3)
		ideal_instructions(a, l);
	else
		deal_with_instructions(rotatesa, rotatesb, l);
}
