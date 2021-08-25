/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:44:27 by glaurent          #+#    #+#             */
/*   Updated: 2021/08/25 08:02:46 by glaurent         ###   ########.fr       */
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

void	push_swap(t_int_list *a, t_int_list *b)
{
	// FAIRE DU PROPRE ET IMPLEMENTER LA PARTIE ALGO
	swap(a);
	swap(b);

	print_circular_linked_list(a, "A");
	print_circular_linked_list(b, "B");
	a = rotate(a, 0);
	print_circular_linked_list(a, "A");
	print_circular_linked_list(b, "B");

	push(a, b);
	print_circular_linked_list(a, "A");
	print_circular_linked_list(b, "B");
	
	b = rotate(b, 1);
	print_circular_linked_list(a, "A");
	print_circular_linked_list(b, "B");

	push(a, b);
	
	print_circular_linked_list(a, "A");
	print_circular_linked_list(b, "B");
	
	free_list(&a);
	free_list(&b);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		print_error();
	push_swap(int_list_from_str_list(ac, av), create_list());
	return (0);
}
