#include "push_swap.h"

int	check_if_sorted_v2(t_int_list *root, int order)
{
	t_int_list	*cur;
	int			ret;
	int			token;

	cur = root->next;
	ret = 1;
	token = 1;
	while (cur != root && cur->next != root)
	{
		if (cur->val * order > cur->next->val * order)
		{
			if (token == 1)
			{
				token = 0;
				ret = cur->index;
			}
			else
				return (-1);
		}
		cur = cur->next;
	}
	if (cur->val * order > cur->next->next->val * order)
		if (token == 0)
			return (-1);
	return (ret);
}

int	check_if_sorted(t_int_list *root, int order)
{
	t_int_list	*current;
	t_int_list	*next;

	current = root->next;
	next = current->next;
	while (current != root && next != root)
	{
		if (current->val * order > next->val * order)
			return (-1);
		current = next;
		next = current->next;
	}
	return (1);
}
