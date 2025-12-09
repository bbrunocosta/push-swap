/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:11:59 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 18:50:44 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "memft.h"

t_context	*ctx_new(int n)
{
	t_context	*ctx;

	ctx = ft_calloc(1, sizeof(t_context));
	if (!ctx)
		return (NULL);
	ctx->number = n;
	return (ctx);
}
