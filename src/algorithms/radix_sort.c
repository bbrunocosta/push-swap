/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:17:37 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 12:25:18 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_bit(t_list *a, t_list *b, size_t bit)
{
	size_t		i;
	size_t		size;
	t_context	*ctx;

	i = 0;
	size = a->count;
	while (i < size)
	{
		ctx = a->first->content;
		if ((ctx->rank >> bit) & 1)
			ra(a, b);
		else
			pb(a, b);
		i++;
	}
	while (b->first)
		pa(a, b);
}

void	radix_sort(t_list *a, t_list *b)
{
	size_t	bit;
	size_t	max_bits;

	if (!a || a->count < 2)
		return ;
	bit = 0;
	max_bits = ilog2_ceil(a->count);
	while (bit < max_bits)
	{
		process_bit(a, b, bit);
		bit++;
	}
}
