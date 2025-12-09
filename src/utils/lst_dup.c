/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:13:40 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 12:13:41 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_dup(t_list *src, t_list *dest, void *(*dup_content)(void *))
{
	t_node	*node;

	node = src->first;
	while (node)
	{
		lst_add_last(dest, lst_new_node(dup_content(node->content)));
		node = node->next;
	}
}
