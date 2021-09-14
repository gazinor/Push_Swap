/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:17:11 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/14 22:33:28 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted_V2(t_int_list *root, int order)
{
	t_int_list	*cur;
	int			ret;
	int			token;

	cur = root->next;
	ret = 1;
	token = 1;
	while (cur != root && cur->next != root)
	{
		if (cur->val * order > cur->next->val * order)
		{
			if (token == 1)
			{
				token = 0;
				ret = cur->index;
			}
			else
				return (-1);
		}
		cur = cur->next;
	}
	if (cur->val * order > cur->next->next->val * order)
		if (token == 0)
			return (-1);
	return (ret);
}

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

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
	{
		if (!s1)
			return (s2[i]);
		else
			return (s1[i]);
	}
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}

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
}

void	make_a_move(t_int_list *a, t_int_list *b, char *move)
{
	//static int moves = 0;

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
	//print_circular_linked_list(a, "\e[4;48;5;74mA");
	//print_circular_linked_list(b, "\e[4;48;5;47mB");
	//getchar();
}

void	instruction_append(t_instruction_list **list, char *inst)
{
	t_instruction_list	*head;
	t_instruction_list	*new;

	//printf("Append \"%s\"\n", inst);
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
