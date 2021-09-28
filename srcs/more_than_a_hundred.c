#include "push_swap.h"

t_find_loop	*recursive_find_loop(t_int_list *list, int precision, int len)
{
	t_int_list			*tmp;
	static t_find_loop	*fl = NULL;

	set_find_loop(&fl, list, precision);
	if (precision >= len / 3)
		return (fl);
	tmp = list->next;
	while (tmp != list)
	{
		if (tmp->index == 0)
			tmp = tmp->next;
		if (tmp->target_index > fl->max_target
			&& tmp->target_index <= fl->max_target + precision)
		{
			fl->max_target = tmp->target_index;
			++fl->count;
		}
		if (tmp != list)
			tmp = tmp->next;
	}
	actualize_find_loop_values(&fl, list, precision);
	return (recursive_find_loop(list, ++precision, len));
}

t_find_loop	find_biggest_loop(t_int_list *list, int len)
{
	t_int_list	*tmp;
	t_find_loop	fl;
	t_find_loop	*fl_copy;

	tmp = list->next;
	fl = (t_find_loop){.loop_index = 0, .max_count = 0,
		.precision = 0};
	while (tmp != list)
	{
		fl_copy = recursive_find_loop(tmp, 1, len);
		if (fl.max_count < fl_copy->max_count)
			fl = *fl_copy;
		tmp = tmp->next;
	}
	set_to_push_values(list, fl.loop_index, fl.precision);
	return (fl);
}

void	push_until_loop_creation(t_int_list *a, t_int_list *b)
{
	t_int_list	*tmp;
	t_int_list	*next;
	int			len;
	t_find_loop	loop;

	tmp = a->next;
	len = get_list_length(a);
	loop = find_biggest_loop(a, len);
	while (check_if_sorted_v2(a, (enum Sort_Order)SMALL_TO_BIG) < 0)
	{
		next = tmp->next;
		is_swap_needed(a, loop);
		if (tmp->to_push == 1 && loop.loop_index != 1)
			make_a_move(a, b, "pb");
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
	make_moves_from_rots(a, b, get_nb_rot_pos(a, 2), 0);
}
