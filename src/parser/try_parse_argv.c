/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_parse_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:07:59 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/26 17:44:28 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stringft.h"
#include "mathft.h"
#include "charft.h"
#include <limits.h>

static int	is_valid_int(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
		str++;
	}
	return (1);
}

static int	parse_split(t_list *s, char *str)
{
	char	**split;
	char	**sp;

	split = ft_split(str);
	sp = split;
	while (sp && *sp)
	{
		if (!ft_is_number(*sp) || !is_valid_int(*sp))
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
		else if (!ft_is_number(*ptr) || !is_valid_int(*ptr))
			return (0);
		else
			lst_add_last(s, lst_new_node(ctx_new(ft_atoi(*ptr))));
		ptr++;
	}
	return (1);
}
