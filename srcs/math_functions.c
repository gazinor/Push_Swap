/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 05:38:38 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/29 05:38:40 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smaller(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	bigger(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	absolute(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
