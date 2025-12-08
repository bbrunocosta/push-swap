#include "push_swap.h"

void	radix_sort(t_list *a, t_list *b)
{
	unsigned int	i;
	unsigned int	log;
	size_t			j;
	size_t			count;
	t_context		*ctx;

	if (!a || a->count < 2)
		return ;
	i = 0;
	log = ilog2_ceil(a->count);
	while (i < log)
	{
		j = 0;
		count = a->count;
		while (j < count)
		{
			ctx = a->first->content;
			if ((ctx->rank >> i) & 1)
				ra(a, b);
			else
				pb(a, b);
			j++;
		}
		while (b->first)
			pa(a, b);
		i++;
	}
}
