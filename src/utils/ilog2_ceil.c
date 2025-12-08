#include "push_swap.h"

int	ilog2_ceil(unsigned int n)
{
	int				log;
	unsigned int	tmp;

	log = -1;
	tmp = n;
	while (tmp)
	{
		tmp >>= 1;
		log++;
	}
	if ((1U << log) < n)
		log++;
	return (log);
}
