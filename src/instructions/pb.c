#include "push_swap.h"

void	pb(t_list *a, t_list *b)
{
	printf("pb\n");
	if (a->count)
		lst_push(b, lst_pop(a));
}
