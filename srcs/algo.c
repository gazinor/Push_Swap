/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:26:53 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/15 09:32:57 by glaurent         ###   ########.fr       */
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
	
int	find_ranged_target_index(t_int_list *a, int min, int max, int len)
{
	t_int_list	*tmp;
	t_int_list	*rev_tmp;
	int			count;
	int			len_manager;

	tmp = a->next;
	rev_tmp = a->prev;
	count = 0;
	len_manager = len;
	//printf("find ranged target between --|%d|-- and --|%d|--\n", min, max);
	while (tmp != a && rev_tmp != a)
	{
		++count;
		if (tmp->target_index >= min && tmp->target_index <= max)
			return (count);
		if (rev_tmp->target_index >= min && rev_tmp->target_index <= max)
			return (len_manager);
		--len_manager;
		tmp = tmp->next;
		rev_tmp = rev_tmp->prev;
	}
	if (len >= 15 && len < 100)
		return (find_ranged_target_index(a, max, max + len / 5, len));
	else if (len >= 100)
		return (find_ranged_target_index(a, max, max + len / 11, len));
	return (find_ranged_target_index(a, max, max + 1, len));
}

int	how_many_rotates(t_int_list *a, int len)
{
	int	hmrotates;
	int	max;

	if (len >= 2 && len < 15)
		max = 1;
	else if (len >= 15 && len <= 200)
		max = len / 5;
	else if (len > 200)
		max = len / 11;
	else
		return (0);
	hmrotates = find_ranged_target_index(a, 1, max, len);
	if (hmrotates <= ((int)(len / 2)))
		return (hmrotates - 1);
	else
		return ((len - hmrotates + 1) * -1);
}

void	fill_instruction_list(t_instruction_list **list,
		int times, char *instruction)
{
	while (times-- > 0)
		instruction_append(list, instruction);
}

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

t_int_list	*get_elem(t_int_list *list, int index)
{
	t_int_list	*tmp;

	tmp = list->next;
	while (tmp != list)
	{
		//printf("Current elem target_index --|%d|--on index [%d]\n",
	//			tmp->target_index, tmp->index);
		if (tmp->index == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (list);
}

void	deal_with_instructions2(int rotA, int rotB, t_instruction_list **l)
{
	if (rotA > 0)
		fill_instruction_list(l, rotA, "ra");
	else if (rotA < 0)
		fill_instruction_list(l, -rotA, "rra");
	if (rotB < 0)
		fill_instruction_list(l, -rotB, "rrb");
	else if (rotB > 0)
		fill_instruction_list(l, rotB, "rb");
}

void	deal_with_instructions(int rotA, int rotB, t_instruction_list **l)
{
	if (rotA < 0 && rotB < 0)
	{
		fill_instruction_list(l, smaller(-rotA, -rotB), "rrr");
		if (-rotA - -rotB > 0)
			fill_instruction_list(l, absolute(-rotA - -rotB), "rra");
		else
			fill_instruction_list(l, absolute(-rotA - -rotB), "rrb");
	}
	else if (rotA > 0 && rotB > 0)
	{
		fill_instruction_list(l, smaller(rotA, rotB), "rr");
		if (rotA - rotB > 0)
			fill_instruction_list(l, absolute(rotA - rotB), "ra");
		else
			fill_instruction_list(l, absolute(rotA - rotB), "rb");
	}
	else
		deal_with_instructions2(rotA, rotB, l);
	instruction_append(l, "pb");
}

void	ideal_instructions(t_int_list *a, t_instruction_list **l)
{
	int e1;
	int e2;
	int e3;

	e1 = get_elem(a, 1)->target_index;
	e2 = get_elem(a, 2)->target_index;
	e3 = get_elem(a, 3)->target_index;
	if (e1 > e2)
	{
		if (e3 > e1 || e3 < e2)
			instruction_append(l, "sa");
		else if (e3 > e2 && e3 < e1)
			instruction_append(l, "ra");
		if (e3 < e2)
			instruction_append(l, "rra");
	}
	else if (e1 < e2)
	{
		instruction_append(l, "rra");
		if (e3 > e1)
			instruction_append(l, "sa");
	}
}

void	are_rots_optimized(int *rotA, int lenB, int *rotB)
{
//	printf("|Before optimization| A : %d | B(%d) : %d\n", *rotA, lenB, *rotB);
	if (*rotA * *rotB < 0)
	{
		if (*rotB < 0)
		{
			if (*rotA - *rotB > bigger(*rotA, lenB + *rotB))
				*rotB = lenB + *rotB;
		}
		else
			if (*rotB - *rotA > bigger(-*rotA,
						absolute(-lenB + *rotB)))
				*rotB = -lenB + *rotB;
	}
//	printf("|After optimization| A : %d | B(%d) : %d\n", *rotA, lenB, *rotB);
}

int get_how_many_to_keep(t_int_list *list)
{
    t_int_list  *tmp;
    int         count;

    tmp = list->next;
    count = 0;
    while (tmp != list)
    {
        if (tmp->index == 0)
            tmp = tmp->next;
        if (tmp->to_push == 0)
            ++count;
        if (tmp != list)
            tmp = tmp->next;
    }
   // printf("i can see --[%d] to keep\n", count);
    return (count);
}

void    set_to_push_values(t_int_list *root, int begining, int precision)
{
	t_int_list	*tmp;
	t_int_list	*copy;
	int			t_i;

	tmp = root->next;
	while (--begining > 0)
		tmp = tmp->next;
	t_i = tmp->target_index;
	tmp->to_push = 0;
  //  printf("[%d] ---> ( %d )  just setted.\n", tmp->index, tmp->target_index);
	copy = tmp->next;
	while (copy != tmp)
	{
		if (copy == root)
			copy = copy->next;
        if (copy->target_index > t_i && copy->target_index <= t_i + precision)
        {
			copy->to_push = 0;
     //       printf("[%d] ---> ( %d )  just setted.\n", copy->index, copy->target_index);
			t_i = copy->target_index;
        }
		else
			copy->to_push = 1;
		if (copy != tmp)
			copy = copy->next;
	}
}

t_find_loop *recursive_find_loop(t_int_list *list, int precision, int len)
{
    t_int_list          *tmp;
    static t_find_loop  *fl = NULL;

//	printf("recursive at index --[%d]-- with precision of %d\n", list->index, precision);
    if (fl == NULL)
        fl = &((t_find_loop){.count = 0, .max_target = list->target_index,
        .loop_index = 0, .max_count = 0});
    if (precision == 1)
        fl->max_count = 0;
    tmp = list->next;
    if (precision >= len / 3)
    {
/*	    	printf("The loop can be found at index[%d]\n\
With a size of      --[ %d ]--\n\
With a precision of --[ %d ]--\n",
fl->loop_index, fl->max_count, fl->precision);
*/        return (fl);
    }
    fl->count = 0;
    fl->max_target = list->target_index;
    while (tmp != list)
    {
        if (tmp->index == 0)
            tmp = tmp->next;
        if (tmp->target_index > fl->max_target && tmp->target_index <= fl->max_target + precision)
        {
            fl->max_target = tmp->target_index;
            ++fl->count;
        }
        if (tmp != list)
            tmp = tmp->next;
    }
  //  printf("count is --[%d]-- | max_count is --[%d]--\n", fl->count, fl->max_count);
    if (fl->count > fl->max_count)
    {
        fl->max_count = fl->count;
        fl->loop_index = list->index;
        fl->precision = precision;
    //    printf("fl->precision setted to %d\n", fl->precision);
    }
	return(recursive_find_loop(list, ++precision, len));
}

t_find_loop find_biggest_loop(t_int_list *list, int len)
{
	t_int_list	*tmp;
    t_find_loop fl;
    t_find_loop *fl_copy;

	tmp = list->next;
	fl = (t_find_loop){.loop_index = 0, .max_count = 0};
    while (tmp != list)
    {
        fl_copy = recursive_find_loop(tmp, 1, len);
    /*	printf("fl copy got index[%d]\n\
    max count--[ %d ]--\n\
    while fl max count is --[%d]--\n",
fl_copy->loop_index, fl_copy->max_count, fl.max_count);
*/        if (fl.max_count < fl_copy->max_count)
            fl = *fl_copy;
        tmp = tmp->next;
    }
	set_to_push_values(list, fl.loop_index, fl.precision);
/*	printf("The REEEEAAAAALLL loop can be found at index[%d]\n\
With a size of      --[ %d ]--\n\
With a precision of --[ %d ]--\n",
fl.loop_index, fl.max_count, fl.precision);
  */  return (fl);
}

int is_swap_needed(t_int_list *list, t_find_loop loop)
{
    int hmtk;
    int loop_index;

    if (loop.loop_index == 1)
        loop_index = 2;
    else
        loop_index = loop.loop_index;
    //printf("Do i swap ?\n");
    hmtk = get_how_many_to_keep(list);
    swap(list);
	set_to_push_values(list, loop_index, loop.precision);
    if (hmtk < get_how_many_to_keep(list))
        ft_putstr_fd("sa", 1);
    else
    {
        swap(list);
    	set_to_push_values(list, loop.loop_index, loop.precision);
        return (0);
    }
    return (1);
}

void	push_until_loop_creation(t_int_list *a, t_int_list *b)
{
	t_int_list	*tmp;
	t_int_list	*next;
    int         len;
    t_find_loop loop;

	tmp = a->next;
    len = get_list_length(a);
	loop = find_biggest_loop(a, len);
	while (check_if_sorted_V2(a, (enum Sort_Order)SMALL_TO_BIG) < 0)
	{
		next = tmp->next;
        is_swap_needed(a, loop);
      //  printf("current elem apres 'tmp = a->next' :  [%d] ---> (%d)     loop_index[%d]     to push ? [%s]\n", tmp->index, tmp->target_index, loop.loop_index, tmp->to_push == 0 ? "non":"oui");
		if (tmp->to_push == 1 && loop.loop_index != 1)
        {
           // printf("I HAVE TO PUSH IT\n");
			make_a_move(a, b, "pb");
        }
		else
			make_a_move(a, b, "ra");
        if (--loop.loop_index == 0)
            loop.loop_index = get_list_length(a);
		tmp = next;
	}
}

void	long_list_algo(t_instruction_list **l, t_int_list *a, t_int_list *b)
{
	push_until_loop_creation(a, b);
	push_all_to_a(a, b, l);
	make_moves_from_rots(a, b, get_nb_rot_rev_pos(a,
	rot_to_lowest_target(a, 1000000) - 1), 0);
}

void	set_instruction_list(t_instruction_list **l, t_int_list *a,
		t_int_list *b)
{
	int	rotatesA;
	int	rotatesB;
	int	lenA;

	lenA = get_list_length(a);
	if (lenA >= 100)
	{
		long_list_algo(l, a, b);
		return ;
	}
	rotatesA = how_many_rotates(a, lenA);
	if (rotatesA < 0)
		rotatesB = get_nb_rot_pos(b,
				get_elem(a, lenA + rotatesA + 1)->target_index);
	else if (rotatesA > 0)
		rotatesB = get_nb_rot_pos(b,
				get_elem(a, rotatesA + 1)->target_index);
	else
		rotatesB = get_nb_rot_pos(b, get_elem(a, 1)->target_index);
	are_rots_optimized(&rotatesA, get_list_length(b), &rotatesB);
	if (lenA == 3)
		ideal_instructions(a, l);
	else
		deal_with_instructions(rotatesA, rotatesB, l);
}
