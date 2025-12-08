#include "push_swap.h"

void	print_stacks(t_list *a, t_list *b)
{
	char	buffer[10000];
	size_t	offset;
	t_node	*na;
	t_node	*nb;

	offset = 0;
	na = a->first;
	nb = b->first;
	offset += sprintf(buffer + offset, "\033[3J\033[H\033[2J\n\n");
	while (na || nb)
	{
		if (na && nb)
			offset += sprintf(buffer + offset, "%-5d %-5d\n",
					((t_context *)na->content)->number,
					((t_context *)nb->content)->number);
		else if (na)
			offset += sprintf(buffer + offset, "%-5d\n",
					((t_context *)na->content)->number);
		else if (nb)
			offset += sprintf(buffer + offset, "      %-5d\n",
					((t_context *)nb->content)->number);
		if (na)
			na = na->next;
		if (nb)
			nb = nb->next;
	}
	offset += sprintf(buffer + offset, "\nA     B\n");
	printf("%s\n", buffer);
}
