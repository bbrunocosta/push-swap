#include "push_swap.h"

void	sa(t_list *a, t_list *b)
{
	t_node	*fisrt;
	t_node	*second;

	printf("sa\n");
	(void)b;
	fisrt = lst_pop(a);
	second = lst_pop(a);
	if (fisrt)
		lst_push(a, fisrt);
	if (second)
		lst_push(a, second);
}
