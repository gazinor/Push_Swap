/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:54:24 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/29 14:07:12 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	**bzerov2(void **str_list, int size)
{
	unsigned char	*ptr;

	ptr = *str_list;
	while (size-- > 0)
		*ptr++ = 0;
	return (str_list);
}

int	is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

void	atoi_error(t_int_list *a, t_int_list *sorted)
{
	free_list(&a);
	free_list(&sorted);
	print_error();
}

void	skip_white(char *str, int *i)
{
	while (is_whitespace(str[*i]))
		++*i;
}

int	ft_atoi(char *nptr, t_int_list *a, t_int_list *sorted)
{
	long	nb;
	int		i;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (!nptr || (nptr && !*nptr))
		atoi_error(a, sorted);
	skip_white(nptr, &i);
	if (!nptr[i])
		atoi_error(a, sorted);
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		atoi_error(a, sorted);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nb = ((nb * 10) + (nptr[i++] - 48));
	skip_white(nptr, &i);
	if (((nptr[i] == '\0') && ((nptr[i - 1] == '-') || (nptr[i - 1] == '+')))
		|| (nptr[i] != '\0' || nb > 2147483647 || nb < -2147483648))
		atoi_error(a, sorted);
	return ((int)nb * sign);
}
