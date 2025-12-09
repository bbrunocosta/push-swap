/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 00:00:00 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 18:55:52 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stringft.h"
#include "hsft.h"
#include <stdlib.h>

static void	push_swap_free(t_list *a,
	t_list *b,
	t_list *temp
)
{
	lst_delete_all(a, free);
	lst_delete_all(b, free);
	lst_delete_all(temp, NULL);
}

int	main(int argc, char **argv)
{
	t_list		a;
	t_list		b;
	t_list		temp;

	a = (t_list){0};
	b = (t_list){0};
	temp = (t_list){0};
	if (argc == 1 || !try_parse_argv(&a, &argv) || has_duplicates(&a, &temp))
	{
		ft_putstr("Error\n");
		push_swap_free(&a, &b, &temp);
		return (1);
	}
	lst_merge_sort(&temp, ctx_compare);
	set_rank(&temp);
	radix_sort(&a, &b);
	push_swap_free(&a, &b, &temp);
	return (0);
}
