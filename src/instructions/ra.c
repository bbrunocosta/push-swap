#include "push_swap.h"

void	ra(t_list *a, t_list *b)
{
	t_node	*node;

	printf("ra\n");
	(void)b;
	if (a->count > 1)
	{
		node = lst_detach(a, a->first);
		lst_add_last(a, node);
	}
}
