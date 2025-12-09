/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 00:00:00 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 13:19:40 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stringft.h"
#include "hsft.h"
#include <stdlib.h>

static int	compare(void *a, void *b)
{
	return (((t_context *)a)->number - ((t_context *)b)->number);
}

static void	*dup_content(void *content)
{
	return (content);
}

static void	lst_dup(t_list *src, t_list *dest, void *(*dup)(void *))
{
	t_node	*node;

	node = src->first;
	while (node)
	{
		lst_add_last(dest, lst_new_node(dup(node->content)));
		node = node->next;
	}
}

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
		ft_putstr("Error\n");
		return (1);
	}
	lst_merge_sort(&b, compare);
	set_rank(&b);
	radix_sort(&a, &c);
	return (0);
}
