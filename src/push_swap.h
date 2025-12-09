/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:01:33 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 12:30:42 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "listft.h"
# include "hsft.h"
# include "charft.h"
# include "mathft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct s_context
{
	int		number;
	size_t	rank;
	char	*rank_string;
}	t_context;

typedef enum e_instruction
{
	INVALID_INSTRUCTION,
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RRA,
	RB,
	RRB,
	RR,
	RRR,
	INTRUCTION_COUNT
}	t_instruction;

typedef void	(*t_instruction_handler) (t_list*, t_list*);

typedef union u_command
{
	char	as_string[3];
	int		as_number;
	struct
	{
		char	a;
		char	b;
		char	c;
		char	d;
	};
}	t_command;

void			pa(t_list *a, t_list *b);
void			pb(t_list *a, t_list *b);
void			sa(t_list *a, t_list *b);
void			sb(t_list *a, t_list *b);
void			ss(t_list *a, t_list *b);
void			ra(t_list *a, t_list *b);
void			rb(t_list *a, t_list *b);
void			rr(t_list *a, t_list *b);
void			rra(t_list *a, t_list *b);
void			rrb(t_list *a, t_list *b);
void			rrr(t_list *a, t_list *b);
void			parse_argv(t_list *s, char ***argv);
t_instruction	parse_command(char command[4]);
char			**ft_split(char *s);
void			free_split(char **split);
t_context		*new_ctx(int n);
int				context_compare(void *a, void *b);
void			*dup_content(void *content);
void			set_rank(t_list *lst);
void			lst_dup(t_list *src, t_list *dest, void*(*dup_content)(void*));
void			radix_sort(t_list *a, t_list *b);
int				ilog2(unsigned int n);
int				ilog2_ceil(unsigned int n);
int				*new_number(int n);
int				compare(void *a, void *b);

#endif
