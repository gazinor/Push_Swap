#include "push_swap.h"

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
