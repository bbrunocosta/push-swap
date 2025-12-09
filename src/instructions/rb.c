/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:16:29 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 12:52:11 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stringft.h"

void	rb(t_list *a, t_list *b)
{
	t_node	*node;

	ft_putstr("rb\n");
	(void)a;
	if (b->count > 1)
	{
		node = lst_detach(b, b->first);
		lst_add_last(b, node);
	}
}
