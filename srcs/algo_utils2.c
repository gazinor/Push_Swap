/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 06:49:57 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/04 07:02:41 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	erase_instructions(t_instruction_list **list)
{
	t_instruction_list	*tmp;

	if (!*list)
		return ;
	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
		tmp = NULL;
	}
	*list = NULL;
}

int	get_nb_rot_pos(t_int_list *list, int top_val)
{
	t_int_list	*tmp;
	int			val;
	int			pos;
	int			lenB;

	tmp = list->next;
	val = 0;
	pos = 1;
	lenB = 0;
	while (tmp != list)
	{
		//printf("val [%d] < target_index [%d] < top_val [%d]\n",
			//	val, tmp->target_index, top_val);
		if (tmp->target_index > val && tmp->target_index < top_val)
		{
			//printf("IT ENTERED\n");
			val = tmp->target_index;
			pos = tmp->index;
		}
		lenB = tmp->index;
		tmp = tmp->next;
	}
	//printf("Trying to get variable under --|%d|--, got --|%d|--\n", top_val, val);
	if (lenB < 2)
		return (0);
	if (pos <= lenB / 2)
	{
		//printf("--|%d|-- number of rotations for b\n", pos - 1);
		return (--pos);
	}
	else
	{
		//printf("number of rotations for b --|%d|--\n", (lenB - pos + 1) * -1);
		return ((lenB - pos + 1) * -1);
	}
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

void	push_all(t_int_list *a, t_int_list *b, t_instruction_list **l)
{
	t_int_list	*t_b;
	int			rotA;

	t_b = b->next;
	erase_instructions(l);
	//printf("--------------------\n|PUSH ALL IN ENTREE|\n--------------------\n");
	while (t_b != b)
	{
		rotA = get_nb_rot_pos(a, t_b->target_index + 2);
		if (rotA < 0)
			while (rotA++ != 0)
				make_a_move(a, b, "rra");
		else if (rotA > 0)
			while (rotA-- != 0)
				make_a_move(a, b, "ra");
		make_a_move(a, b, "pa");
		t_b = t_b->next;
	}
	//printf("--------------------\n|PUSH ALL OUT SORTIE|\n--------------------\n");
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

int	checks_before_instruction(t_instruction_list **l, t_int_list *a, t_int_list *b)
{
	int	rot;

//	if (a->next->val > a->next->next->val)
//		make_a_move(a, b, "sa");
	rot = get_nb_rot_pos(a, 2);
	if (check_if_sorted_V2(a, (enum Sort_Order)SMALL_TO_BIG) > 0 && rot != 0)
	{
		if (rot < 0)
			while (rot++ != 0)
				make_a_move(a, b, "rra");
		else if (rot > 0)
			while (rot-- != 0)
				make_a_move(a, b, "ra");
	}
	if (lowest_target(a, a->next->target_index) == 1)
		if (check_if_sorted(a, (enum Sort_Order)SMALL_TO_BIG) == 1)
		{
			rot = get_nb_rot_pos(a,
					rot_to_highest_target(b, b->next->target_index) + 1);
			if (rot < 0)
				while (rot++ != 0)
					make_a_move(a, b, "rrb");
			else if (rot > 0)
				while (rot-- != 0)
					make_a_move(a, b, "rb");
			push_all(a, b, l);
			return (-1);
		}
	if (check_if_sorted(a, (enum Sort_Order)SMALL_TO_BIG) == 1 &&
			check_if_sorted(b, (enum Sort_Order)BIG_TO_SMALL))
	{
		push_all(a, b, l);
		return (-1);
	}
	return (1);
}
