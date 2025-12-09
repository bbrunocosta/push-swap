/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:16:42 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 12:52:30 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stringft.h"

void	rra(t_list *a, t_list *b)
{
	t_node	*node;

	ft_putstr("rra\n");
	(void)b;
	if (a->count > 1)
	{
		node = lst_detach(a, a->last);
		lst_add_first(a, node);
	}
}
