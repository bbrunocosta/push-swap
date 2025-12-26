/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 00:00:00 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/26 16:45:34 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_number(t_node *node)
{
	return (((t_context *)node->content)->number);
}

void	sort_two(t_list *a, t_list *b)
{
	if (get_number(a->first) > get_number(a->first->next))
		sa(a, b);
}

void	sort_three(t_list *a, t_list *b)
{
	int	first;
	int	second;
	int	third;

	first = get_number(a->first);
	second = get_number(a->first->next);
	third = get_number(a->first->next->next);
	if (first > second && second < third && first < third)
		sa(a, b);
	else if (first > second && second > third)
	{
		sa(a, b);
		rra(a, b);
	}
	else if (first > second && second < third && first > third)
		ra(a, b);
	else if (first < second && second > third && first < third)
	{
		sa(a, b);
		ra(a, b);
	}
	else if (first < second && second > third && first > third)
		rra(a, b);
}
