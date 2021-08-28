/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:26:53 by glaurent          #+#    #+#             */
/*   Updated: 2021/08/28 12:40:13 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_list_length(t_int_list *a)
{
	t_int_list	*tmp;
	int			i;

	tmp = a->next;
	i = 0;
	while (tmp != a)
	{
		tmp = tmp->next;
		++i;
	}
	return (i);
}
	
int	find_index(t_int_list *a, int index)
{
	t_int_list	*tmp;
	int			count;

	tmp = a->next;
	count = 0;
	while (tmp != a)
	{
		++count;
		if (tmp->target_index == index)
			return (count);
		tmp = tmp->next;
	}
	return (count);
}

int	how_many_rotates(t_int_list *a, int index)
{
	int	hmrotates;
	int	len;

	hmrotates = find_index(a, index);
	len = get_list_length(a);
	printf("len : %d   |  hmr : %d\n", len, hmrotates);
	if (hmrotates <= ((int)(len / 2)))
		return (hmrotates - 1);
	else
		return ((len - hmrotates + 1) * -1);
}
void	fill_instruction_list(t_instruction_list **list,
		int times, char *instruction)
{
	while (times-- > 0)
	{
		instruction_append(list, instruction);
	}
}

void	set_instruction_list(t_instruction_list **l, t_int_list *a)
{
	static int			index = 1;
	int					rotatesA;

	rotatesA = how_many_rotates(a, index);
	if (rotatesA < 0)
	{
		rotatesA *= -1;
		fill_instruction_list(l, rotatesA, "rra");
	}
	else if (rotatesA > 0)
		fill_instruction_list(l, rotatesA, "ra");
	++index;
}
