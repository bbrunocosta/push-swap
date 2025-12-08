#include "push_swap.h"

void	rra(t_list *a, t_list *b)
{
	t_node	*node;

	printf("rra\n");
	(void)b;
	if (a->count > 1)
	{
		node = lst_detach(a, a->last);
		lst_add_first(a, node);
	}
}
