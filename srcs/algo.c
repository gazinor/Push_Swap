/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:26:53 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/15 09:32:57 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_list_length(t_int_list *a)
{
	t_int_list	*tmp;
	int			i;

	tmp = a->next;
	i = 0;
	while (tmp != a)
	{
		tmp = tmp->next;
		++i;
	}
	return (i);
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
	//printf("find ranged target between --|%d|-- and --|%d|--\n", min, max);
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
	if (len >= 15 && len <= 200)
		return (find_ranged_target_index(a, max, max + len / 5, len));
	else if (len > 200)
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

void	fill_instruction_list(t_instruction_list **list,
		int times, char *instruction)
{
	while (times-- > 0)
		instruction_append(list, instruction);
}

int	smaller(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	bigger(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	absolute(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

t_int_list	*get_elem(t_int_list *list, int index)
{
	t_int_list	*tmp;

	tmp = list->next;
	while (tmp != list)
	{
		//printf("Current elem target_index --|%d|--on index [%d]\n",
	//			tmp->target_index, tmp->index);
		if (tmp->index == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (list);
}

void	deal_with_instructions2(int rotA, int rotB, t_instruction_list **l)
{
	if (rotA > 0)
		fill_instruction_list(l, rotA, "ra");
	else if (rotA < 0)
		fill_instruction_list(l, -rotA, "rra");
	if (rotB < 0)
		fill_instruction_list(l, -rotB, "rrb");
	else if (rotB > 0)
		fill_instruction_list(l, rotB, "rb");
}

void	deal_with_instructions(int rotA, int rotB, t_instruction_list **l)
{
	if (rotA < 0 && rotB < 0)
	{
		fill_instruction_list(l, smaller(-rotA, -rotB), "rrr");
		if (-rotA - -rotB > 0)
			fill_instruction_list(l, absolute(-rotA - -rotB), "rra");
		else
			fill_instruction_list(l, absolute(-rotA - -rotB), "rrb");
	}
	else if (rotA > 0 && rotB > 0)
	{
		fill_instruction_list(l, smaller(rotA, rotB), "rr");
		if (rotA - rotB > 0)
			fill_instruction_list(l, absolute(rotA - rotB), "ra");
		else
			fill_instruction_list(l, absolute(rotA - rotB), "rb");
	}
	else
		deal_with_instructions2(rotA, rotB, l);
	instruction_append(l, "pb");
}

void	ideal_instructions(t_int_list *a, t_instruction_list **l)
{
	int e1;
	int e2;
	int e3;

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

void	are_rots_optimized(int *rotA, int lenB, int *rotB)
{
//	printf("|Before optimization| A : %d | B(%d) : %d\n", *rotA, lenB, *rotB);
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
//	printf("|After optimization| A : %d | B(%d) : %d\n", *rotA, lenB, *rotB);
}

void	set_to_push_values(t_int_list *root, int begining)
{
	t_int_list	*tmp;
	t_int_list	*copy;
	int			t_i;

	tmp = root->next;
	while (--begining != 0)
		tmp = tmp->next;
	copy = tmp->next;
	t_i = copy->target_index;
	while (copy != tmp)
	{
		if (copy == root)
			copy = copy->next;
		if (t_i > copy->target_index)
			copy->to_push = 1;
		else
			t_i = copy->target_index;
		if (copy != tmp)
			copy = copy->next;
	}
}

int	recursive_create_loop(t_int_list *list, int precision)
{
	(void)precision;
	(void)list;
	return (-156487);
	////////////////TO DO / A FAIRE / HASTA LA VIDA / STRUDEL
}

int	find_biggest_loop(t_int_list *list)
{
	t_int_list	*tmp;
	int			loop_index;
	int			loop_len;
	int			len;
/*
//
//	Pour cette fonction je veux :
//	- partir d'un element de la liste
//	- chercher en recursive avec une precision qui augmente d'1 chaque tour,
//		quelle est la plus grande taille que peut faire la loop
//	- 
//
*/
	tmp = list->next;
	loop_index = 0;
	loop_len = 0;
	while (tmp != list && tmp->next != list)
	{
		len = 0;
		while (tmp->next != list && tmp->target_index < tmp->next->target_index
				&& ++len)
			tmp = tmp->next;
		if (len > loop_len)
		{
			loop_len = len;
			loop_index = tmp->index - len;
		}
		tmp = tmp->next;
	}
	set_to_push_values(list, loop_index);
	return (loop_index);
}

void	push_until_loop_creation(t_int_list *a, t_int_list *b)
{
	t_int_list	*tmp;
	t_int_list	*next;
	int			until;

	tmp = a->next;
	until = find_biggest_loop(a);
//	printf("the loop can be found at index[%d]\n", until);
	while (check_if_sorted_V2(a, (enum Sort_Order)SMALL_TO_BIG) < 0)
	{
		next = tmp->next;
		if (tmp->to_push == 1)
			make_a_move(a, b, "pb");
		else
			make_a_move(a, b, "ra");
		tmp = next;
	}
}

void	long_list_algo(t_instruction_list **l, t_int_list *a, t_int_list *b)
{
	push_until_loop_creation(a, b);
	push_all_to_a(a, b, l);
	checks_before_instruction(l, a, b);
}

void	set_instruction_list(t_instruction_list **l, t_int_list *a,
		t_int_list *b)
{
	int	rotatesA;
	int	rotatesB;
	int	lenA;

	lenA = get_list_length(a);
	if (lenA >= 100)
	{
		long_list_algo(l, a, b);
		return ;
	}
	rotatesA = how_many_rotates(a, lenA);
	if (rotatesA < 0)
		rotatesB = get_nb_rot_pos(b,
				get_elem(a, lenA + rotatesA + 1)->target_index);
	else if (rotatesA > 0)
		rotatesB = get_nb_rot_pos(b,
				get_elem(a, rotatesA + 1)->target_index);
	else
		rotatesB = get_nb_rot_pos(b, get_elem(a, 1)->target_index);
	are_rots_optimized(&rotatesA, get_list_length(b), &rotatesB);
	if (lenA == 3)
		ideal_instructions(a, l);
	else
		deal_with_instructions(rotatesA, rotatesB, l);
}
