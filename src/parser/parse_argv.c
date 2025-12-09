/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:07:59 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 13:17:06 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stringft.h"
#include "mathft.h"

void	parse_argv(t_list *s, char ***argv)
{
	char	**ptr;
	char	**split;
	char	**split_ptr;

	ptr = *argv + 1;
	while (*ptr)
	{
		if (ft_strchr(*ptr, ' '))
		{
			split = ft_split(*ptr);
			split_ptr = split;
			while (split_ptr && *split_ptr)
			{
				lst_add_last(s,
					lst_new_node(new_ctx(ft_atoi(*split_ptr))));
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
