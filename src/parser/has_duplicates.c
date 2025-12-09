/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:38:08 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 18:54:32 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "hsft.h"
#include <stdlib.h>

static void	*not_dup_content(void *content)
{
	return (content);
}

int	has_duplicates(t_list *a, t_list *temp)
{
	t_hashset	*hs;

	lst_dup(a, temp, not_dup_content);
	hs = hs_from_lst(a, hash_int_knuth, ctx_compare, free);
	hs_free(hs, NULL);
	return (hs->count != a->count);
}
