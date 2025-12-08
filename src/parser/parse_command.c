#include "push_swap.h"

#define IDX(ch) ((ch) == 0 ? 26 : (ch) - 'a')

e_instruction	parse_command(char command[4])
{
	e_instruction	map[27][27][27];

	map[IDX('r')][IDX('a')][IDX('\0')] = RA;
	map[IDX('r')][IDX('r')][IDX('a')] = RRA;
	map[IDX('r')][IDX('b')][IDX('\0')] = RB;
	map[IDX('r')][IDX('r')][IDX('b')] = RRB;
	map[IDX('r')][IDX('r')][IDX('\0')] = RR;
	map[IDX('r')][IDX('r')][IDX('r')] = RRR;
	map[IDX('s')][IDX('a')][IDX('\0')] = SA;
	map[IDX('s')][IDX('b')][IDX('\0')] = SB;
	map[IDX('s')][IDX('s')][IDX('\0')] = SS;
	map[IDX('p')][IDX('a')][IDX('\0')] = PA;
	map[IDX('p')][IDX('b')][IDX('\0')] = PB;
	return (map[IDX(command[0])][IDX(command[1])][IDX(command[2])]);
}
