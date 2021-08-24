#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_int_list
{
	int		val;
	struct	s_int_list *prev;
	struct	s_int_list *next;
}				t_int_list;

#endif
