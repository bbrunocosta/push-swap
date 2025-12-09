/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:13:16 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 13:26:49 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rank(t_list *lst)
{
	size_t		i;
	t_node		*node;
	t_context	*ctx;

	node = lst->first;
	i = 0;
	while (node)
	{
		ctx = node->content;
		ctx->rank = i;
		node = node->next;
		i++;
	}
}
