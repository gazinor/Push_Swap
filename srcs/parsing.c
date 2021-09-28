/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:38:44 by glaurent          #+#    #+#             */
/*   Updated: 2021/08/25 10:02:19 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error", 2);
	exit(-1);
}

int	sort_list(int val, t_int_list *root)
{
	t_int_list	*tmp;

	tmp = root->next;
	while (tmp != root && val > tmp->val)
		tmp = tmp->next;
	if (tmp->val == val)
		return (-1);
	add_tail(val, tmp);
	return (42);
}

t_int_list	*int_list_from_str_list(int nbr_of_lists, char **L)
{
	int			i;
	int			add_to_list;
	t_int_list	*a;
	t_int_list	*sorted_list;

	i = 0;
	a = create_list();
	sorted_list = create_list();
	while (++i < nbr_of_lists && ft_atoi(L[i], a, sorted_list))
		;
	i = 0;
	while (++i < nbr_of_lists)
	{
		add_to_list = ft_atoi(L[i], a, sorted_list);
		add_tail(add_to_list, a);
		if (sort_list(add_to_list, sorted_list) == -1)
		{
			free_list(&a);
			free_list(&sorted_list);
			print_error();
		}
	}
	set_target_indexes(a, sorted_list);
	free_list(&sorted_list);
	return (a);
}
