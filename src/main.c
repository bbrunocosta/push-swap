#include "push_swap.h"
#include <math.h>

int	main(int argc, char **argv)
{
	t_list		a;
	t_list		b;
	t_list		c;
	t_hashset	*hs;

	a = (t_list){0};
	b = (t_list){0};
	c = (t_list){0};
	parse_argv(&a, &argv);
	lst_dup(&a, &b, dup_content);
	hs = hs_from_lst(&a, hash_int_knuth, compare, free);
	if (argc == 1 || hs->count != a.count)
	{
		printf("Error\n");
		return (1);
	}
	lst_merge_sort(&b, context_compare);
	set_rank(&b);
    radix_sort(&a, &c);
	return (0);
}
