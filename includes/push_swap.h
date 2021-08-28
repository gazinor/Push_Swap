#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

enum Sort_Order
{
	BIG_TO_SMALL = -1,
	SMALL_TO_BIG = 1
};

typedef struct	s_int_list
{
	int					val;
	int					index;
	int					target_index;
	struct s_int_list	*prev;
	struct s_int_list	*next;
}				t_int_list;

typedef struct	s_instruction_list
{
	char						*instruction;
	struct s_instruction_list	*next;
}				t_instruction_list;

t_int_list	*create_list(void);

void		empty_list(t_int_list *list);

void		free_list(t_int_list **list);

void		remove_elem(t_int_list *elem);

void		add_head(int val, t_int_list *root);

void		add_tail(int val, t_int_list *root);

void		swap(t_int_list *root);

void		print_circular_linked_list(t_int_list *list, char *which_list);

t_int_list	*rotate(t_int_list *root, int reverse);

void		push(t_int_list	*from, t_int_list *to);

void		push_swap(t_int_list *a, t_int_list *b);

void		ft_putstr_fd(char *str, int fd);

void		print_error(void);

int			is_whitespace(char c);

int			ft_atoi(char *nptr);

int			sort_list(int val, t_int_list *root);

t_int_list	*int_list_from_str_list(int nbr_of_lists, char **L);

void		set_indexes(t_int_list *root);

void		set_target_indexes(t_int_list *root, t_int_list *sorted_list);

int			check_if_sorted(t_int_list *root, int order);

void		make_a_move(t_int_list *list, t_int_list *maybe, char *move);

int			str_compare(char *s1, char *s2);

void		fill_instruction_list(t_instruction_list **list,
		int times, char *instruction);

void		set_instruction_list(t_instruction_list **l, t_int_list *a);

int			how_many_rotates(t_int_list *a, int index);

int			find_index(t_int_list *a, int index);

int			get_list_length(t_int_list *a);

void		**bzeroV2(void **str_list, int size);

void		instruction_append(t_instruction_list **list, char *inst);
#endif
