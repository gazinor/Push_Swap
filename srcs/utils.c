/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:50:01 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/15 05:41:54 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_circular_linked_list(t_int_list *list, char *which_list)
{
	t_int_list	*tmp;
	char		*to_push;

	tmp = list->next;
	printf("\n\e[48;5;166m\e[4;38;5;52mPrint %s list\e[0;48;5;166m :\n\n",
		which_list);
	while (tmp != list)
	{
		if (tmp->to_push == 1)
			to_push = "oui";
		else
			to_push = "non";
		printf("Index [%d](should be at [%d]) : \
				|%d| -- next is --> |%d|     push ? %s\n",
			tmp->index, tmp->target_index, tmp->val,
			tmp->next->val, to_push);
		tmp = tmp->next;
	}
	printf("\e[0m\n");
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	i = write(fd, str, i);
	i = write(fd, "\n", 1);
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
