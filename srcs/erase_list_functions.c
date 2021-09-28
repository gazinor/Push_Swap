#include "push_swap.h"

void	free_list(t_int_list **list)
{
	empty_list(*list);
	free(*list);
	*list = NULL;
}

void	empty_list(t_int_list *list)
{
	t_int_list	*tmp;
	t_int_list	*next;

	tmp = list->next;
	while (tmp != list)
	{
		next = tmp->next;
		if (tmp)
			free(tmp);
		tmp = NULL;
		tmp = next;
	}
}

void	remove_elem(t_int_list *elem)
{
	elem->prev->next = elem->next;
	elem->next->prev = elem->prev;
	if (elem)
		free(elem);
	elem = NULL;
}
