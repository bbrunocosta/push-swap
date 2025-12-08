#include "push_swap.h"

void	pa(t_list *a, t_list *b)
{
	printf("pa\n");
	if (b->count)
		lst_push(a, lst_pop(b));
}
