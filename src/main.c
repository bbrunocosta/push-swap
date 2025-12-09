/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 00:00:00 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 17:59:21 by bcosta-b         ###   ########.fr       */
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

static void	*not_dup_content(void *content)
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
static void push_swap_free(t_list *a,
	t_list *b,
	t_list *temp,
	t_hashset *hs
)
{
	lst_delete_all(a, free);
	lst_delete_all(b, free);
	lst_delete_all(temp, NULL);
	hs_free(hs,NULL);
}
int	main(int argc, char **argv)
{
	t_list		a;
	t_list		b;
	t_list		temp;
	t_hashset	*hs;

	a = (t_list){0};
	b = (t_list){0};
	temp = (t_list){0};
	parse_argv(&a, &argv);
	lst_dup(&a, &temp, not_dup_content);
	hs = hs_from_lst(&a, hash_int_knuth, compare, free);
	if (argc == 1 || hs->count != a.count)
	{
		ft_putstr("Error\n");
		push_swap_free(&a, &b, &temp, hs);
		return (1);
	}
	lst_merge_sort(&temp, compare);
	set_rank(&temp);
	radix_sort(&a, &b);
	push_swap_free(&a, &b, &temp, hs);
	return (0);
}
