/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:17:00 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 12:52:55 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stringft.h"

void	sa(t_list *a, t_list *b)
{
	t_node	*fisrt;
	t_node	*second;

	ft_putstr("sa\n");
	(void)b;
	fisrt = lst_pop(a);
	second = lst_pop(a);
	if (fisrt)
		lst_push(a, fisrt);
	if (second)
		lst_push(a, second);
}
