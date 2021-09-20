/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:02:45 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/20 23:45:21 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deal_with_ret(t_int_list *a, t_int_list *b, char *line, int ret)
{
	if (ret > 0)
		make_a_move_no_print(a, b, line);
	else if (ret == -1)
	{
		free_list(&a);
		free_list(&b);
		free(line);
		print_error();
	}
	else
	{
		free(line);
		line = NULL;
	}
}

int	main(int ac, char **av)
{
	t_int_list	*a_copy;
	t_int_list	*b_copy;
	char		*line;
	int			ret;

	if (ac < 2)
		return (1);
	a_copy = int_list_from_str_list(ac, av);
	b_copy = create_list();
	ret = get_next_line(0, &line);
	while (ret > 0)
	{
		deal_with_ret(a_copy, b_copy, line, ret);
		ret = get_next_line(0, &line);
	}
	deal_with_ret(a_copy, b_copy, line, ret);
	if (check_if_sorted(a_copy, (enum Sort_Order)SMALL_TO_BIG) == -1 ||
			b_copy->next != b_copy)
		ft_putstr_fd("KO", 1);
	else
		ft_putstr_fd("OK", 1);
}
