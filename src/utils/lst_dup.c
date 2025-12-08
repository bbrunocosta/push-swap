#include "push_swap.h"

void	lst_dup(t_list *src, t_list *dest, void *(*dup_content)(void *))
{
	t_node	*node;

	node = src->first;
	while (node)
	{
		lst_add_last(dest, lst_new_node(dup_content(node->content)));
		node = node->next;
	}
}
