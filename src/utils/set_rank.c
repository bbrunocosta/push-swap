#include "push_swap.h"

void	set_rank(t_list *lst)
{
	t_node		*node;
	size_t		i;
	t_context	*ctx;

	node = lst->first;
	i = 0;
	while (node)
	{
		ctx = node->content;
		ctx->rank = i;
		node = node->next;
		i++;
	}
}
