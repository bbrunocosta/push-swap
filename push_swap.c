#include "listft.h"
#include "hsft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	multiway_push_sort(t_list *a, t_list *b, int n_chunks);
void radix_base4(t_list *a, t_list *b);


void pa(t_list *a, t_list *b)
{
	printf("PA\n");
	if (b->count)
		lst_push(a, lst_pop(b));
}
void pb(t_list *a, t_list *b)
{
	printf("PB\n");
	if (a->count)
		lst_push(b, lst_pop(a));
}
void sa(t_list *a, t_list *b)
{
	printf("SA\n");
	(void)b;
	t_node *fisrt = lst_pop(a);
	t_node *second = lst_pop(a);
	if (fisrt)
		lst_push(a, fisrt);
	if (second)
		lst_push(a, second);
}
void sb(t_list *a, t_list *b)
{
	printf("SB\n");
	(void) a;
	t_node *fisrt = lst_pop(b);
	t_node *second = lst_pop(b);
	if (fisrt)
		lst_push(b, fisrt);
	if (second)
		lst_push(b, second);
}
void ss(t_list *a, t_list *b)
{
	printf("SS\n");
	sa(a,b);
	sb(a,b);
}
void ra(t_list *a, t_list *b)
{
	printf("RA\n");
	(void)b;
	if(a->count > 1)
	{
		t_node *node = lst_detach(a, a->first);
		lst_add_last(a, node);
	}
}
void rra(t_list *a, t_list *b)
{
	printf("RRA\n");
	(void)b;
	if(a->count > 1)
	{
		t_node *node = lst_detach(a, a->last);
		lst_add_first(a, node);
	}
}

void rb(t_list *a, t_list *b)
{
	printf("RB\n");
	(void)a;
	if (b->count > 1)
	{
		t_node *node = lst_detach(b, b->first);  // <--- Muda para o primeiro!
		lst_add_last(b, node);                  // <--- Coloca no final.
	}
}

void rrb(t_list *a, t_list *b)
{
	printf("RRB\n");
	(void)a;
	if(b->count > 1)
	{
		t_node *node = lst_detach(b, b->last);
		lst_add_first(b, node);
	}
}
void rr(t_list *a, t_list *b)
{
	printf("RR\n");
	ra(a,b);
	rb(a,b);
}
void rrr(t_list *a, t_list *b)
{
	printf("RRR\n");
	rra(a,b);
	rrb(a,b);
}
typedef enum
{
	INVALID_INSTRUCTION, PA, PB, SA, SB, SS, RA,RRA, RB, RRB, RR, RRR, INTRUCTION_COUNT
} e_instruction;

typedef void (*f_instruction)(t_list*,t_list*);


int	*new_number(int n)
{
	int	*number;

	number = calloc(1, sizeof(int));
	if (!number)
		return (NULL);
	*number = n;
	return (number);
}



typedef union u_command
{
	char asString[3];
	int asNumber;
	struct {
		char a;
		char b;
		char c;
		char d;
	};
} t_command;

#define IDX(ch) ((ch) == 0 ? 26 : (ch) - 'a')

e_instruction parse_command(char command[4])
{
	e_instruction map[27][27][27] = {
		[IDX('r')][IDX('a')][IDX('\0')] = RA,
		[IDX('r')][IDX('r')][IDX('a')] = RRA,
		[IDX('r')][IDX('b')][IDX('\0')] = RB,
		[IDX('r')][IDX('r')][IDX('b')] = RRB,
		[IDX('r')][IDX('r')][IDX('\0')] = RR,
		[IDX('r')][IDX('r')][IDX('r')] = RRR,
		[IDX('s')][IDX('a')][IDX('\0')] = SA,
		[IDX('s')][IDX('b')][IDX('\0')] = SB,
		[IDX('s')][IDX('s')][IDX('\0')] = SS,
		[IDX('p')][IDX('a')][IDX('\0')] = PA,
		[IDX('p')][IDX('b')][IDX('\0')] = PB
	};

	return map[IDX(command[0])][IDX(command[1])][IDX(command[2])];
}

int ilog2(unsigned int n) {
    int log = -1;
    while (n) 
	{
        n >>= 1;   // divide por 2
        log++;
    }
    return log; // retorna floor(log2(n))
}

int ilog2_ceil(unsigned int n) {
    int log = -1;
    unsigned int tmp = n;

    while (tmp) {
        tmp >>= 1;
        log++;
    }
    // se n não for potência de 2, precisa subir 1
    if ((1U << log) < n)
        log++;
    return log;
}

#include "mathft.h"
typedef struct s_context
{
	int number;
	size_t rank;
}	t_context;
void print_stacks(t_list *a, t_list *b)
{
    char buffer[10000];   // buffer grande o suficiente
    size_t offset = 0;

    t_node *na = a->first;
    t_node *nb = b->first;

    // clear screen
    offset += sprintf(buffer + offset, "\033[3J\033[H\033[2J");

    while (na || nb)
    {
        if (na && nb)
            offset += sprintf(buffer + offset, "%-5d %-5d\n",
                              ((t_context*)na->content)->number, ((t_context*)nb->content)->number);
        else if (na)
            offset += sprintf(buffer + offset, "%-5d\n", ((t_context*)na->content)->number);
        else if (nb)
            offset += sprintf(buffer + offset, "      %-5d\n", ((t_context*)nb->content)->number);

        if (na) na = na->next;
        if (nb) nb = nb->next;
    }

    offset += sprintf(buffer + offset, "\nA     B\n");

    printf("%s", buffer);
}
int	compare(void *a, void *b)
{
	return (((t_context*)a)->number - ((t_context*)b)->number);
}
t_context	*new_ctx(int n)
{
	t_context	*ctx;

	ctx = calloc(1, sizeof(t_context));
	if (!ctx)
		return (NULL);
	ctx->number = n;
	return (ctx);
}
void parse_argv(t_list *s, char ***argv)
{
	char **ptr = *argv;
	ptr++;
	while(*ptr)
	{
		lst_add_last(s, lst_new_node(new_ctx(ft_atoi(*ptr))));
		ptr++;
	}
}

int context_compare(void *a, void *b)
{
	return (((t_context*)a)->number - ((t_context*)b)->number);
}
void *dup_content(void *content)
{
	return content;
}
void lst_dup(t_list *src, t_list *dest, void*(*dup_content)(void*))
{
	t_node *node = src->first;
	while(node)
	{
		lst_add_last(dest, lst_new_node(dup_content(node->content)));
		node = node->next;
	}
}
void	set_rank(t_list *lst)
{
	t_node *node = lst->first;
	size_t i = 0;
	while(node)
	{
		t_context *ctx = node->content;
		ctx->rank = i;
		node = node->next;
		i++;
	}
}

void	chunk_sort(t_list *a, t_list *b);


void radix_sort(t_list *a, t_list *b)
{

	unsigned int i = 0;
	unsigned int log = ilog2_ceil(a->count);
	while(i < log)
	{
		size_t j = 0;
		size_t count = a->count;
		while(j < count)
		{
			if(((t_context*)a->first->content)->rank >> i & 1)
				ra(a, b);
			else
			pb(a, b);
			j++;
		}
		i++;
	}

	while(b->first)
		pa(a, b);
}

int main(int argc, char **argv)
{
	t_list a = {0};
	t_list b = {0};
	t_list c = {0};
	t_hashset *hs;

	parse_argv(&a, &argv);
	lst_dup(&a, &b, dup_content);
	hs = hs_from_lst(&a, hash_int_knuth, compare, free);

	if (argc == 1 || hs->count != a.count)
	{
		printf("Error\n");
		// hs_free(hs, free);
		// lst_delete_all(&a, free);
		// lst_delete_all(&b, free);
		return (1);
	}

	lst_merge_sort(&b, context_compare);
	set_rank(&b);
	// lst_delete_all(&b, NULL);

	radix_base4(&a, &c);
	multiway_push_sort(&a, &c, 3);
	// radix_sort(&a, &c);
	// chunk_sort(&a, &c);

	// print_stacks(&a, &c);
	// hs_free(hs, free);
	// lst_delete_all(&a, free);
	// lst_delete_all(&b, free);








	// f_instruction instruction_map[] = {
	// 	[PA]=pa,
	// 	[PB]=pb,
	// 	[SA]=sa,
	// 	[SB]=sb,
	// 	[SS]=ss,
	// 	[RA]=ra,
	// 	[RRA]=rra,
	// 	[RB]=rb,
	// 	[RRB]=rrb,
	// 	[RR]=rr,
	// 	[RRR]=rrr
	// };
	// do
	// {
	// 	print_stacks(&a, &b);
	// 	char *command = calloc(4, sizeof(char));
	// 	scanf("%s", command);
	// 	instruction_map[parse_command(command)](&a, &b);
	// }
	// while(1);

	// print_stacks(&a, &b);
	// lst_delete_all(&a, free);
	// lst_delete_all(&b, free);
	return (0);
}



