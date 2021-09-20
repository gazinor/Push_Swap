#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "get_next_line.h"

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
	int					to_push;
	struct s_int_list	*prev;
	struct s_int_list	*next;
}				t_int_list;

typedef struct	s_instruction_list
{
	char						*instruction;
	struct s_instruction_list	*next;
}				t_instruction_list;

typedef struct	s_find_loop
{
	int loop_index;
    int count;
    int max_target;
    int max_count;
    int precision;
}               t_find_loop;

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

int			check_if_sorted_V2(t_int_list *root, int order);

void		make_a_move(t_int_list *list, t_int_list *maybe, char *move);

void		make_a_move_part2(t_int_list *list, t_int_list *maybe, char *move);

void		make_a_move_no_print(t_int_list *list, t_int_list *b, char *move);

int			str_compare(char *s1, char *s2);

void		fill_instruction_list(t_instruction_list **list,
		int times, char *instruction);

void		set_instruction_list(t_instruction_list **l, t_int_list *a,
		t_int_list *b);

int			how_many_rotates(t_int_list *a, int index);

int			find_ranged_target_index(t_int_list *a, int min, int max, int len);

int			get_list_length(t_int_list *a);

void		**bzeroV2(void **str_list, int size);

void		instruction_append(t_instruction_list **list, char *inst);

int			checks_before_instruction(t_instruction_list **l,
		t_int_list *a, t_int_list *b);

void		erase_instructions(t_instruction_list **list);

void		push_all_to_a(t_int_list *a, t_int_list *b, t_instruction_list **l);

int			get_nb_rot_pos(t_int_list *list, int top_val);

int			get_nb_rot_rev_pos(t_int_list *list, int under_val);

t_int_list	*get_elem(t_int_list *list, int index);

void		deal_with_instructions(int rotA, int rotB, t_instruction_list **l);

void		deal_with_instructions2(int rotA, int rotB, t_instruction_list **l);

int			smaller(int a, int b);

int			bigger(int a, int b);

int			absolute(int a);

void		execute_instruction_list(t_instruction_list **l,
		t_int_list *a, t_int_list *b);

void		ideal_instructions(t_int_list *a, t_instruction_list **l);

int			rot_to_highest_target(t_int_list *list, int target);

int	        rot_to_lowest_target(t_int_list *list, int target);

void		are_rots_optimized(int *rotA, int lenB, int *rotB);

void		long_list_algo(t_instruction_list **l,
		t_int_list *a, t_int_list *b);

void        exec_n_instructions(t_int_list *a, t_int_list *b, int n, char *inst);

void        make_moves_from_rots(t_int_list *a, t_int_list *b, int rotA, int rotB);

void        make_moves_from_rots2(t_int_list *a, t_int_list *b, int rotA, int rotB);

void	push_until_loop_creation(t_int_list *a, t_int_list *b);

t_find_loop find_biggest_loop(t_int_list *list, int len);

t_find_loop *recursive_find_loop(t_int_list *list, int precision, int len);

void	set_to_push_values(t_int_list *root, int begining, int precision);

#endif
