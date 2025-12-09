/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:16:18 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 12:52:01 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stringft.h"

void	ra(t_list *a, t_list *b)
{
	t_node	*node;

	ft_putstr("ra\n");
	(void)b;
	if (a->count > 1)
	{
		node = lst_detach(a, a->first);
		lst_add_last(a, node);
	}
}
