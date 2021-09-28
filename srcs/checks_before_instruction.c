#include "push_swap.h"

int	checks_before_instruction(t_instruction_list **l, t_int_list *a,
		t_int_list *b)
{
	int	rot;

	rot = get_nb_rot_pos(a, 2);
	if (check_if_sorted_v2(a, (enum Sort_Order)SMALL_TO_BIG) > 0)
	{
		if (b->next == b)
		{
			if (rot < 0)
				while (rot++ != 0)
					make_a_move(a, b, "rra");
			else if (rot > 0)
				while (rot-- != 0)
					make_a_move(a, b, "ra");
		}
		else
		{
			push_all_to_a(a, b, l);
			return (-1);
		}
	}
	if (lowest_target(a, a->next->target_index) == 1)
		if (check_if_sorted(a, (enum Sort_Order)SMALL_TO_BIG) == 1)
		{
			rot = get_nb_rot_pos(a,
					rot_to_highest_target(b, b->next->target_index) + 1);
			if (rot < 0)
				while (rot++ != 0)
					make_a_move(a, b, "rrb");
			else if (rot > 0)
				while (rot-- != 0)
					make_a_move(a, b, "rb");
			push_all_to_a(a, b, l);
			return (-1);
		}
	if (check_if_sorted(a, (enum Sort_Order)SMALL_TO_BIG) == 1 &&
			check_if_sorted(b, (enum Sort_Order)BIG_TO_SMALL))
	{
		push_all_to_a(a, b, l);
		return (-1);
	}
	if (get_list_length(a) > 9 &&
			a->next->target_index == a->next->next->target_index + 1)
		make_a_move(a, b, "sa");
	return (1);
}
