/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_list_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:17:11 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/20 23:42:02 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_int_list **list)
{
	empty_list(*list);
	free(*list);
	*list = NULL;
}

void	empty_list(t_int_list *list)
{
	t_int_list	*tmp;
	t_int_list	*next;

	tmp = list->next;
	while (tmp != list)
	{
		next = tmp->next;
		if (tmp)
			free(tmp);
		tmp = NULL;
		tmp = next;
	}
}

void	remove_elem(t_int_list *elem)
{
	elem->prev->next = elem->next;
	elem->next->prev = elem->prev;
	if (elem)
		free(elem);
	elem = NULL;
}
