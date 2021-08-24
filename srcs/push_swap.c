/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:44:27 by glaurent          #+#    #+#             */
/*   Updated: 2021/08/24 07:44:31 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int_list	*create_list(void)
{
    t_int_list *root;
   
	root = malloc(sizeof(*root));
    if ( root != NULL )
    {
        root->prev = root;
        root->next = root;
    }
    return root;
}

void	empty_list(t_int_list *list)
{
	t_int_list *tmp;
	t_int_list *next;

	tmp = list->next;
	while (tmp != list)
	{
		next = tmp->next;
		if (tmp)
			free(tmp);
		tmp = next;
	}
}

void	free_list(t_int_list **list)
{
	empty_list(*list);
	free(*list);
	*list = NULL;
}

void	remove_elem(t_int_list *elem)
{
	elem->prev->next = elem->next;
	elem->next->prev = elem->prev;
	if (elem)
		free(elem);
	elem = NULL;
}

void	add_head(int val, t_int_list *root)
{
	t_int_list *new;

	new = malloc(sizeof(*new));
    if (new != NULL)
    {
        new->val = val;
        new->prev = root;
        new->next = root->next;
        root->next->prev = new;
        root->next = new;
    }
}

void	add_tail(int val, t_int_list *root)
{
	t_int_list *new;

	new = malloc(sizeof(*new));
    if (new != NULL)
    {
        new->val = val;
        new->prev = root->prev;
        new->next = root;
        root->prev->next = new;
        root->prev = new;
    }
}

void	swap(t_int_list *root)
{
	int tmp;

	if (root->next != root && root->next->next != root)
	{
		tmp = root->next->val;
		root->next->val = root->next->next->val;
		root->next->next->val = tmp;
	}
}


void	print_circular_linked_list(t_int_list *list)
{
	t_int_list *tmp;

	tmp = list->next;
	printf("\nprint list :\n\n|");
	while (tmp != list)
	{
		printf("%d -- next is --> %d\n", tmp->val, tmp->next->val);
		tmp = tmp->next;
	}
	printf("|\n");
}

t_int_list	*rotate(t_int_list *root, int reverse)
{
	t_int_list	*new_spot;
	int			tmp;

	tmp = 0;
	if (reverse == 0)
	{
		new_spot = root->next;
		root->prev->next = new_spot;
		new_spot->prev = root->prev;
		root->prev = new_spot;
		root->next = new_spot->next;
		new_spot->next->prev = root;
		new_spot->next = root;
	}
	else
	{
		new_spot = root->prev;
		new_spot->next = root->next;
		root->next->prev = new_spot;
		root->next = new_spot;
		root->prev = new_spot->prev;
		new_spot->prev->next = root;
		new_spot->prev = root;
	}
	return (root);
}

void	push(t_int_list	*from, t_int_list *to)
{
	if (from->next != from)
	{
		add_head(from->next->val, to);
		remove_elem(from->next);
	}
}

void	push_swap(t_int_list *a, t_int_list *b)
{
	// FAIRE DU PROPRE ET IMPLEMENTER LA PARTIE ALGO
	swap(a);

	push(a, b);
	
	a = rotate(a, 0);
	
	print_circular_linked_list(a);
	print_circular_linked_list(b);
	
	free_list(&a);
	free_list(&b);
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

int	is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *nptr)
{
	long	nb;
	int		i;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (is_whitespace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nb = ((nb * 10) + (nptr[i++] - 48));
	if ((nptr[i] != '\0' && !is_whitespace(nptr[i]) && !(nptr[i] >= '0'
				&& nptr[i] <= '9')) || nb > 2147483647 || nb < -2147483648)
		print_error();
	return ((int)nb * sign);
}

t_int_list	*int_list_from_str_list(int nbr_of_lists, char **L)
{
	int	i;
	t_int_list	*a;

	i = 0;
	a = create_list();
	while (++i < nbr_of_lists && ft_atoi(L[i]))
		;
	i = 0;
	while (++i < nbr_of_lists)
		add_tail(ft_atoi(L[i]), a);
	return (a);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		print_error();
	push_swap(int_list_from_str_list(ac, av), create_list());
	return (0);
}
