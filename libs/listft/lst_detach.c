/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_detach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:36:30 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/09/23 19:27:02 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listft.h"
#include <stdlib.h>

t_node	*lst_detach(t_node *node)
{
	if (node->prev)
		node->prev->next = node->next;
	else
		node->list->first = node->next;
	if (node->next)
		node->next->prev = node->prev;
	else
		node->list->last = node->prev;
	if (node->list->count > 0)
		node->list->count--;
	node->prev = NULL;
	node->next = NULL;
	node->list = NULL;
	return (node);
}
