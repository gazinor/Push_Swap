/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:17:11 by glaurent          #+#    #+#             */
/*   Updated: 2021/08/28 12:17:45 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_int_list *root, int order)
{
	t_int_list	*current;
	t_int_list	*next;

	current = root->next;
	next = current->next;
	while (current != root && next != root)
	{
		if (current->val * order > next->val * order)
			return (-1);
		current = next;
		next = current->next;
	}
	return (1);
}

int	str_compare(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		;
	return (s1[i] - s2[i]);
}

void	make_a_move_part2(t_int_list *a, t_int_list *b, char *move)
{
	if (!str_compare(move, "ra"))
		rotate(a, 0);
	else if (!str_compare(move, "rb"))
		rotate(a, 0);
	else if (!str_compare(move, "rr"))
	{
		rotate(a, 0);
		rotate(b, 0);
	}
	else if (!str_compare(move, "rra"))
		rotate(a, 1);
	else if (!str_compare(move, "rrb"))
		rotate(a, 1);
	else if (!str_compare(move, "rrr"))
	{
		rotate(a, 1);
		rotate(b, 1);
	}
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
	make_a_move_part2(a, b, move);
	ft_putstr_fd(move, 1);
	print_circular_linked_list(a, "A");
	print_circular_linked_list(b, "B");
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
