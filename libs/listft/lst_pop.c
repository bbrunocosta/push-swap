/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:36:30 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/09/23 20:44:27 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listft.h"
#include <stdlib.h>

t_node	*lst_pop(t_list *lst)
{
	if (!lst->count)
		return (NULL);
	return (lst_detach(lst->first));
}
