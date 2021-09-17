/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 06:49:57 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/15 09:31:50 by glaurent         ###   ########.fr       */
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

int	get_nb_rot_rev_pos(t_int_list *list, int under_val)
{
	t_int_list	*tmp;
	int			val;
	int			pos;
	int			lenB;

	tmp = list->next;
	val = 1000000;
	pos = 1;
	lenB = 0;
	while (tmp != list)
	{
	//	printf("val [%d] < target_index [%d] < under_val [%d]\n",
	//			val, tmp->target_index, under_val);
		if (tmp->target_index < val && tmp->target_index > under_val)
		{
//			printf("IT ENTERED\n");
			val = tmp->target_index;
			pos = tmp->index;
		}
		lenB = tmp->index;
		tmp = tmp->next;
	}
//	printf("Trying to get variable above --|%d|--, got --|%d|--\n", under_val, val);
	if (lenB < 2)
		return (0);
	if (val == 1000000)
		return (get_nb_rot_rev_pos(list,
					rot_to_lowest_target(list, val) - 1));
	if (pos <= lenB / 2)
	{
	//	printf("--|%d|-- number of rotations for b\n", pos - 1);
		return (--pos);
	}
	else
	{
	//	printf("number of rotations for b --|%d|--\n", (lenB - pos + 1) * -1);
		return ((lenB - pos + 1) * -1);
	}
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
//		printf("val [%d] < target_index [%d] < top_val [%d]\n",
//				val, tmp->target_index, top_val);
		if (tmp->target_index > val && tmp->target_index < top_val)
		{
//			printf("IT ENTERED\n");
			val = tmp->target_index;
			pos = tmp->index;
		}
		lenB = tmp->index;
		tmp = tmp->next;
	}
//	printf("Trying to get variable under --|%d|--, got --|%d|--\n", top_val, val);
	if (lenB < 2 || top_val == 0)
		return (0);
	if (val == 0)
		return (get_nb_rot_pos(list,
					rot_to_highest_target(list, 1) + 1));
	if (pos <= lenB / 2)
	{
	//	printf("--|%d|-- number of rotations for b\n", pos - 1);
		return (--pos);
	}
	else
	{
	//	printf("number of rotations for b --|%d|--\n", (lenB - pos + 1) * -1);
		return ((lenB - pos + 1) * -1);
	}
}

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
   // printf("LOWEST TARGET IN A IS : %d\n", lowest);
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

void	set_shortest_alignment(int *rA, int *rB, t_int_list *a, t_int_list *b)
{
	t_int_list	*tmp;
	int			shortest;
	int			keep_rot;
	int			keep_index;
	int			lenB;

	tmp = b->next;
	shortest = 1000000;
	lenB = get_list_length(b);
	while (tmp != b)
	{
		keep_rot = get_nb_rot_rev_pos(a, tmp->target_index);
		keep_index = tmp->index - 1;
		are_rots_optimized(&keep_rot, lenB, &keep_index);
		if (absolute(keep_rot) + absolute(keep_index) < shortest)
		{
			shortest = absolute(keep_rot) + absolute(keep_index);
			*rA = keep_rot;
			*rB = keep_index;
	//        printf("rot A : --[ %d ]--\nrot B : --[ %d ]--\n", *rA, *rB);
		}
		tmp = tmp->next;
	}
}

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
    //printf("rot A -- [ %d ] --\nrot B -- [ %d ] --\n", rotA, rotB);
	are_rots_optimized(&rotA, get_list_length(b), &rotB);
    //printf("NOW OPTIMIZED :\nrot A -- [ %d ] --\nrot B -- [ %d ] --\n", rotA, rotB);
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

void	push_all_to_a(t_int_list *a, t_int_list *b, t_instruction_list **l)
{
	t_int_list	*t_b;
	int			rA;
	int			rB;

	t_b = b->next;
	erase_instructions(l);
	rA = 0;
	rB = 0;
//	printf("--------------------\n|PUSH ALL IN ENTREE|\n--------------------\n");
	while (b->next != b)
	{
		set_shortest_alignment(&rA, &rB, a, b);
		make_moves_from_rots(a, b, rA, rB);
		make_a_move(a, b, "pa");
		t_b = t_b->next;
	}
//	printf("--------------------\n|PUSH ALL OUT SORTIE|\n--------------------\n");
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

int	checks_before_instruction(t_instruction_list **l, t_int_list *a,
		t_int_list *b)
{
	int	rot;

	rot = get_nb_rot_pos(a, 2);
	if (check_if_sorted_V2(a, (enum Sort_Order)SMALL_TO_BIG) > 0)
	{
		if (b->next == b)
		{
			if (rot < 0)
				while (rot++ != 0)
					make_a_move(a, b, "rra");
			else if (rot > 0)
				while (rot-- != 0)
					make_a_move(a, b, "ra");
		}
		else
		{
			push_all_to_a(a, b, l);
			return (-1);
		}
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
			push_all_to_a(a, b, l);
			return (-1);
		}
	if (check_if_sorted(a, (enum Sort_Order)SMALL_TO_BIG) == 1 &&
			check_if_sorted(b, (enum Sort_Order)BIG_TO_SMALL))
	{
		push_all_to_a(a, b, l);
		return (-1);
	}
	if (get_list_length(a) > 9 &&
			a->next->target_index == a->next->next->target_index + 1)
		make_a_move(a, b, "sa");
	return (1);
}
