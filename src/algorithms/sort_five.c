/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 00:00:00 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/26 16:46:19 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_rank(t_node *node)
{
	return (((t_context *)node->content)->rank);
}

static int	find_min_position(t_list *a)
{
	t_node	*current;
	int		pos;
	int		min_pos;
	int		min_rank;

	current = a->first;
	pos = 0;
	min_pos = 0;
	min_rank = (int)get_rank(current);
	while (current)
	{
		if ((int)get_rank(current) < min_rank)
		{
			min_rank = (int)get_rank(current);
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

static void	push_min_to_b(t_list *a, t_list *b)
{
	int		min_pos;
	size_t	size;

	size = a->count;
	min_pos = find_min_position(a);
	if (min_pos <= (int)size / 2)
	{
		while (min_pos-- > 0)
			ra(a, b);
	}
	else
	{
		while (min_pos++ < (int)size)
			rra(a, b);
	}
	pb(a, b);
}

void	sort_five(t_list *a, t_list *b)
{
	if (a->count == 5)
		push_min_to_b(a, b);
	if (a->count == 4)
		push_min_to_b(a, b);
	sort_three(a, b);
	if (b->count > 0)
		pa(a, b);
	if (b->count > 0)
		pa(a, b);
}
