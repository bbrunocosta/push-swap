/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_int_knuth.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 23:01:55 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/10/03 01:59:17 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsft.h"

size_t hash_int_knuth(void *key, size_t size)
{
	size_t	A;

	if ((sizeof(void*) == 8))
		A = 11400714819323198485ull;
	else
		A = 2654435761u;
	return (*(size_t*) key * A % size);
}