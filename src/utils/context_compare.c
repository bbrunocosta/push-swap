#include "push_swap.h"

int	context_compare(void *a, void *b)
{
	return (((t_context *)a)->number - ((t_context *)b)->number);
}
