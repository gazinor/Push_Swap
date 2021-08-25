/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:50:01 by glaurent          #+#    #+#             */
/*   Updated: 2021/08/25 07:34:48 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_int_list **list)
{
	empty_list(*list);
	free(*list);
	*list = NULL;
}

void	print_circular_linked_list(t_int_list *list, char *which_list)
{
	t_int_list	*tmp;

	tmp = list->next;
	printf("\n\ec\e[48;5;166m\e[4;38;5;52mPrint %s list\e[0;48;5;166m :\n\n", which_list);
	while (tmp != list)
	{
		printf("Index [%d](should be at [%d]) : |%d| -- next is --> |%d|\n", tmp->index, tmp->target_index, tmp->val, tmp->next->val);
		tmp = tmp->next;
	}
	printf("\e[0m\n");
	getchar();
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	write(fd, str, i);
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

t_int_list	*int_list_from_str_list(int nbr_of_lists, char **L)
{
	int	i;
	int	add_to_list;
	t_int_list	*a;
	t_int_list	*sorted_list;

	i = 0;
	a = create_list();
	sorted_list = create_list();
	while (++i < nbr_of_lists && ft_atoi(L[i]))
		;
	i = 0;
	while (++i < nbr_of_lists)
	{
		add_to_list = ft_atoi(L[i]);
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
