#include "push_swap.h"

int	ilog2(unsigned int n)
{
	int	log;

	log = -1;
	while (n)
	{
		n >>= 1;
		log++;
	}
	return (log);
}
