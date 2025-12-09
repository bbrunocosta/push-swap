/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_parse_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:07:59 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 18:53:52 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stringft.h"
#include "mathft.h"

static int	parse_split(t_list *s, char *str)
{
	char	**split;
	char	**sp;

	split = ft_split(str);
	sp = split;
	while (sp && *sp)
	{
		if (!ft_is_number(*sp))
			return (free_split(split), 0);
		lst_add_last(s, lst_new_node(ctx_new(ft_atoi(*sp++))));
	}
	free_split(split);
	return (1);
}

int	try_parse_argv(t_list *s, char ***argv)
{
	char	**ptr;

	ptr = *argv + 1;
	while (*ptr)
	{
		if (ft_strchr(*ptr, ' '))
		{
			if (!parse_split(s, *ptr))
				return (0);
		}
		else if (!ft_is_number(*ptr))
			return (0);
		else
			lst_add_last(s, lst_new_node(ctx_new(ft_atoi(*ptr))));
		ptr++;
	}
	return (1);
}
