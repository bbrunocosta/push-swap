#include "push_swap.h"

void	rrb(t_list *a, t_list *b)
{
	t_node	*node;

	printf("rrb\n");
	(void)a;
	if (b->count > 1)
	{
		node = lst_detach(b, b->last);
		lst_add_first(b, node);
	}
}
