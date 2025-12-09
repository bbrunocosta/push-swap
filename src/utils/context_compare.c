/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_compare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:13:06 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 12:13:07 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	context_compare(void *a, void *b)
{
	return (((t_context *)a)->number - ((t_context *)b)->number);
}
