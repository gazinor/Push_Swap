/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:55:55 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/20 22:56:15 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_int_list	*a;
	t_int_list	*b;

	a = int_list_from_str_list(ac, av);
	b = create_list();
	push_swap(a, b);
	return (0);
}
