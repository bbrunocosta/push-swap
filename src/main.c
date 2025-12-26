/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 00:00:00 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/26 17:00:35 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stringft.h"
#include "hsft.h"
#include <stdlib.h>

static int	push_swap_free(t_list *a,
	t_list *b,
	t_list *temp,
	int error_code
)
{
	lst_delete_all(a, free);
	lst_delete_all(b, free);
	lst_delete_all(temp, NULL);
	return (error_code);
}

static int	is_sorted(t_list *lst)
{
	t_node		*current;
	t_context	*curr_ctx;
	t_context	*next_ctx;

	if (!lst || !lst->first || !lst->first->next)
		return (0);
	current = lst->first;
	while (current->next)
	{
		curr_ctx = (t_context *)current->content;
		next_ctx = (t_context *)current->next->content;
		if (curr_ctx->number > next_ctx->number)
			return (0);
		current = current->next;
	}
	return (1);
}

static void	sort(t_list *a, t_list *b)
{
	if (a->count == 2)
		sort_two(a, b);
	else if (a->count == 3)
		sort_three(a, b);
	else if (a->count <= 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_list		a;
	t_list		b;
	t_list		temp;

	a = (t_list){0};
	b = (t_list){0};
	temp = (t_list){0};
	if (argc == 1)
		return (0);
	if (!try_parse_argv(&a, &argv) || has_duplicates(&a, &temp))
	{
		ft_putstr("Error\n");
		return (push_swap_free(&a, &b, &temp, 1));
	}
	if (is_sorted(&a))
		return (push_swap_free(&a, &b, &temp, 0));
	lst_merge_sort(&temp, ctx_compare);
	set_rank(&temp);
	sort(&a, &b);
	return (push_swap_free(&a, &b, &temp, 0));
}
