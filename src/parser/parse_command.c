/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:07:30 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 12:55:30 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "memft.h"

static int	get_idx(char ch)
{
	if (ch == 0)
		return (26);
	return (ch - 'a');
}

t_instruction	parse_command(char command[4])
{
	t_instruction	map[27][27][27];

	ft_memset(map, 0, sizeof(map));
	map[get_idx('r')][get_idx('a')][get_idx('\0')] = RA;
	map[get_idx('r')][get_idx('r')][get_idx('a')] = RRA;
	map[get_idx('r')][get_idx('b')][get_idx('\0')] = RB;
	map[get_idx('r')][get_idx('r')][get_idx('b')] = RRB;
	map[get_idx('r')][get_idx('r')][get_idx('\0')] = RR;
	map[get_idx('r')][get_idx('r')][get_idx('r')] = RRR;
	map[get_idx('s')][get_idx('a')][get_idx('\0')] = SA;
	map[get_idx('s')][get_idx('b')][get_idx('\0')] = SB;
	map[get_idx('s')][get_idx('s')][get_idx('\0')] = SS;
	map[get_idx('p')][get_idx('a')][get_idx('\0')] = PA;
	map[get_idx('p')][get_idx('b')][get_idx('\0')] = PB;
	return (map[get_idx(command[0])][get_idx(command[1])]
		[get_idx(command[2])]);
}
