#include "push_swap.h"

void	parse_argv(t_list *s, char ***argv)
{
	char	**ptr;
	char	**split;
	char	**split_ptr;

	ptr = *argv;
	ptr++;
	while (*ptr)
	{
		if (strchr(*ptr, ' '))
		{
			split = ft_split(*ptr);
			split_ptr = split;
			while (split_ptr && *split_ptr)
			{
				lst_add_last(s, lst_new_node(new_ctx(ft_atoi(*split_ptr))));
				split_ptr++;
			}
			free_split(split);
		}
		else
		{
			lst_add_last(s, lst_new_node(new_ctx(ft_atoi(*ptr))));
		}
		ptr++;
	}
}
