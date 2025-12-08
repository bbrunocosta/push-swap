#include "push_swap.h"

void	rb(t_list *a, t_list *b)
{
	t_node	*node;

	printf("rb\n");
	(void)a;
	if (b->count > 1)
	{
		node = lst_detach(b, b->first);
		lst_add_last(b, node);
	}
}
