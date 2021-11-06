/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:17:11 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/20 23:42:02 by glaurent         ###   ########.fr       */
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

void	instruction_append(t_instruction_list **list, char *inst)
{
	t_instruction_list	*head;
	t_instruction_list	*new;

	if (!*list)
	{
		*list = malloc(sizeof(*list));
		(*list)->next = NULL;
		(*list)->instruction = inst;
	}
	else
	{
		head = *list;
		new = malloc(sizeof(*new));
		while (head && head->next)
		{
			head = head->next;
		}
		if (new)
		{
			new->instruction = inst;
			new->next = NULL;
			head->next = new;
		}
	}
}

void	fill_instruction_list(t_instruction_list **list,
		int times, char *instruction)
{
	while (times-- > 0)
		instruction_append(list, instruction);
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
