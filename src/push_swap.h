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

/* Estruturas e tipos */
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
}	e_instruction;

typedef void (*f_instruction)(t_list*, t_list*);

typedef union u_command
{
	char	asString[3];
	int		asNumber;
	struct {
		char a;
		char b;
		char c;
		char d;
	};
}	t_command;

/* Instruções push */
void	pa(t_list *a, t_list *b);
void	pb(t_list *a, t_list *b);

/* Instruções swap */
void	sa(t_list *a, t_list *b);
void	sb(t_list *a, t_list *b);
void	ss(t_list *a, t_list *b);

/* Instruções rotate */
void	ra(t_list *a, t_list *b);
void	rb(t_list *a, t_list *b);
void	rr(t_list *a, t_list *b);

/* Instruções reverse rotate */
void	rra(t_list *a, t_list *b);
void	rrb(t_list *a, t_list *b);
void	rrr(t_list *a, t_list *b);

/* Parser */
void			parse_argv(t_list *s, char ***argv);
e_instruction	parse_command(char command[4]);

/* Utilidades de string */
char	**ft_split(char *s);
void	free_split(char **split);

/* Utilidades de contexto */
t_context	*new_ctx(int n);
int			context_compare(void *a, void *b);
void		*dup_content(void *content);
void		set_rank(t_list *lst);

/* Utilidades de lista */
void	lst_dup(t_list *src, t_list *dest, void*(*dup_content)(void*));

/* Visualização */
void	print_stacks(t_list *a, t_list *b);

/* Algoritmos */
void	radix_sort(t_list *a, t_list *b);

/* Utilitários matemáticos */
int		ilog2(unsigned int n);
int		ilog2_ceil(unsigned int n);

/* Funções auxiliares */
int		*new_number(int n);
int		compare(void *a, void *b);

#endif
