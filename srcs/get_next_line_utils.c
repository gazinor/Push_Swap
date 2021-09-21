/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:26:19 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/20 20:13:54 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char const *s)
{
	size_t		size;

	size = 0;
	while (*(s + size))
		size++;
	return (size);
}

int	ft_isprint(int c)
{
	if (c >= ' ' && c < 127)
		return (1);
	return (0);
}
