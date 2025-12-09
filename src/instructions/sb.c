/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:17:10 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 12:53:05 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stringft.h"

void	sb(t_list *a, t_list *b)
{
	t_node	*fisrt;
	t_node	*second;

	ft_putstr("sb\n");
	(void)a;
	fisrt = lst_pop(b);
	second = lst_pop(b);
	if (fisrt)
		lst_push(b, fisrt);
	if (second)
		lst_push(b, second);
}
