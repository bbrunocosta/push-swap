#include "push_swap.h"

int	compare(void *a, void *b)
{
	return (((t_context *)a)->number - ((t_context *)b)->number);
}
