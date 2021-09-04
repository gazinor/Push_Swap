/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:44:27 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/04 06:16:46 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_int_list *root)
{
	int	val;
	int	target_index;

	if (root->next != root && root->next->next != root)
	{
		val = root->next->val;
		root->next->val = root->next->next->val;
		root->next->next->val = val;
		target_index = root->next->target_index;
		root->next->target_index = root->next->next->target_index;
		root->next->next->target_index = target_index;
		set_indexes(root);
	}
}

t_int_list	*rotate(t_int_list *root, int reverse)
{
	t_int_list	*new_spot;

	if (root->next == root || root->next->next == root)
		return (root);
	new_spot = reverse == 1 ? root->prev : root->next;
	if (reverse == 0)
	{
		root->prev->next = new_spot;
		new_spot->prev = root->prev;
		root->prev = new_spot;
		root->next = new_spot->next;
		new_spot->next->prev = root;
		new_spot->next = root;
	}
	else
	{
		new_spot->next = root->next;
		root->next->prev = new_spot;
		root->next = new_spot;
		root->prev = new_spot->prev;
		new_spot->prev->next = root;
		new_spot->prev = root;
	}
	set_indexes(root);
	return (root);
}

void	push(t_int_list	*from, t_int_list *to)
{
	if (from->next != from)
	{
		add_head(from->next->val, to);
		to->next->target_index = from->next->target_index;
		remove_elem(from->next);
		set_indexes(from);
		set_indexes(to);
	}
}

void	execute_instruction_list(t_instruction_list **l, t_int_list *a, t_int_list *b)
{
	t_instruction_list	*tmp;

	while (*l != NULL)
	{
		if (checks_before_instruction(l, a, b) == -1)
		{
			erase_instructions(l);
			break;
		}
		if (*l != NULL)
		{
			//printf("Execute \"%s\"\n", (*l)->instruction);
			make_a_move(a, b, (*l)->instruction);
			tmp = *l;
			*l = (*l)->next;
			free(tmp);
			tmp = NULL;
		}
		//getchar();
	}
}

void	push_swap(t_int_list *a, t_int_list *b)
{
	t_instruction_list	*instruction_list;

	instruction_list = NULL;
	while (check_if_sorted(a, (enum Sort_Order)SMALL_TO_BIG) == -1 ||
			b->next != b)
	{
		set_instruction_list(&instruction_list, a, b);
		execute_instruction_list(&instruction_list, a, b);
	}
	free_list(&a);
	free_list(&b);
	//free_list(&instruction_list);
}

int	main(int ac, char **av)
{
	push_swap(int_list_from_str_list(ac, av), create_list());
	return (0);
}
