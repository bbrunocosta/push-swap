#include "push_swap.h"

void	sb(t_list *a, t_list *b)
{
	t_node	*fisrt;
	t_node	*second;

	printf("sb\n");
	(void)a;
	fisrt = lst_pop(b);
	second = lst_pop(b);
	if (fisrt)
		lst_push(b, fisrt);
	if (second)
		lst_push(b, second);
}
