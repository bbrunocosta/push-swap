/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:12:20 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 12:55:58 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "memft.h"

int	*new_number(int n)
{
	int	*number;

	number = ft_calloc(1, sizeof(int));
	if (!number)
		return (NULL);
	*number = n;
	return (number);
}
