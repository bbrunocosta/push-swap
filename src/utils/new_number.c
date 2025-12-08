#include "push_swap.h"

int	*new_number(int n)
{
	int	*number;

	number = calloc(1, sizeof(int));
	if (!number)
		return (NULL);
	*number = n;
	return (number);
}
