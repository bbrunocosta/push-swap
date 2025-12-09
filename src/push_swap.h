/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:01:33 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 18:55:00 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "listft.h"

typedef struct s_context
{
	int		number;
	size_t	rank;
	char	*rank_string;
}	t_context;

t_context		*ctx_new(int n);
int				ctx_compare(void *a, void *b);
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
int				try_parse_argv(t_list *s, char ***argv);
void			radix_sort(t_list *a, t_list *b);
void			set_rank(t_list *lst);
int				has_duplicates(t_list *a, t_list *temp);

#endif
