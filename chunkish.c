#include "listft.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


/*
** ========================================
**   Estruturas básicas e forward declarations
** ========================================
*/

void print_stacks_base3(t_list *a, t_list *b);
void print_stacks(t_list *a, t_list *b);
void pa(t_list *a, t_list *b);
void pb(t_list *a, t_list *b);
void sa(t_list *a, t_list *b);
void rrr(t_list *a, t_list *b);
void rr(t_list *a, t_list *b);
void rrb(t_list *a, t_list *b);
void rb(t_list *a, t_list *b);
void rra(t_list *a, t_list *b);
void ra(t_list *a, t_list *b);
void ss(t_list *a, t_list *b);
void sb(t_list *a, t_list *b);
void pbb(t_list *a, t_list *b);



typedef struct s_context
{
	int number;
	size_t rank;
	char *rank_string;
}	t_context;


typedef struct s_move
{
	int rank;   // rank do elemento a mover
	int pos_a;  // posição onde deve ser inserido em A
	int pos_b;  // posição atual em B
	int cost;   // custo total da operação
	int dir_a;  // direção da rotação de A (1 = ra, -1 = rra)
	int dir_b;  // direção da rotação de B (1 = rb, -1 = rrb)
}	t_move;
#include <stdio.h>
void rotate_to_top(t_list *a, t_list *b, int pos, char stack)
{
	int size = (stack == 'a') ? a->count : b->count;
	if (size <= 0 || pos < 0 || pos >= size)
		return;

	if (pos <= size / 2)
	{
		while (pos-- > 0)
			(stack == 'a') ? ra(a, b) : rb(a, b);
	}
	else
	{
		int steps = size - pos;
		while (steps-- > 0)
			(stack == 'a') ? rra(a, b) : rrb(a, b);
	}
}

int	find_insert_pos(t_list *a, int rank)
{
	if (!a || a->count == 0)
		return (0);

	t_node *n = a->first;
	int pos = 0;
	int best_pos = 0;

	// busca o ponto exato entre curr e next
	while (n)
	{
		int curr = ((t_context*)n->content)->rank;
		int next = (n->next)
			? ((t_context*)n->next->content)->rank
			: ((t_context*)a->first->content)->rank;

		// caso normal (rank entre curr e next)
		if (curr < rank && rank < next)
			return (pos + 1);

		// caso circular: transição do maior para o menor
		if (curr > next && (rank > curr || rank < next))
			return (pos + 1);

		n = n->next;
		pos++;
	}

	return (best_pos % a->count);
}




/*
** Encontra a posição (0-index) do nó com o rank desejado na pilha.
** Retorna -1 se o rank não for encontrado.
**
** Exemplo:
** stack = [5, 1, 9, 3] com ranks [2, 0, 3, 1]
** find_position(stack, 3) → 2  (pois o rank 3 está na 3ª posição)
*/
int	find_position(t_list *stack, int rank)
{
	t_node	*node;
	int		pos;

	if (!stack || stack->count == 0)
		return (-1);
	node = stack->first;
	pos = 0;
	while (node)
	{
		if (((t_context *)node->content)->rank == rank)
			return (pos);
		node = node->next;
		pos++;
	}
	return (-1);
}

t_move	calc_move_cost(t_list *a, t_list *b, int rank)
{
	t_move m;
	m.rank = rank;
	m.pos_b = find_position(b, rank);
	m.pos_a = find_insert_pos(a, rank);
	int size_a = a->count;
	int size_b = b->count;

	m.dir_a = (m.pos_a <= size_a / 2) ? 1 : -1;
	m.dir_b = (m.pos_b <= size_b / 2) ? 1 : -1;

	int cost_a = (m.dir_a == 1) ? m.pos_a : size_a - m.pos_a;
	int cost_b = (m.dir_b == 1) ? m.pos_b : size_b - m.pos_b;

	m.cost = cost_a + cost_b;
	return (m);
}



t_move	find_best_move(t_list *a, t_list *b)
{
	t_move best;
	best.cost = 2147483647;
	t_node *n = b->first;

	while (n)
	{
		t_context *ctx = n->content;
		t_move current = calc_move_cost(a, b, ctx->rank);
		if (current.cost < best.cost)
			best = current;
		n = n->next;
	}
	return (best);
}


void	exec_move(t_list *a, t_list *b, t_move m)
{
	while (m.pos_a > 0 && m.pos_b > 0 && m.dir_a == m.dir_b)
	{
		if (m.dir_a == 1)
			rr(a, b);
		else
			rrr(a, b);
		m.pos_a--;
		m.pos_b--;
	}
	rotate_to_top(a, b, m.pos_a, 'a');
	rotate_to_top(a, b, m.pos_b, 'b');
	pa(a, b);
}


void	greedy_merge(t_list *a, t_list *b)
{
	while (b->count > 0)
	{
		t_move best = find_best_move(a, b);
		exec_move(a, b, best);
	}
}


void	distribute_chunks(t_list *a, t_list *b, int n_chunks)
{
	int max_rank = a->count - 1;
	int chunk_size = ceil((double)(max_rank + 1) / n_chunks);
	t_node *n = a->first;

	while (a->count > 0)
	{
		int rank = ((t_context*)a->first->content)->rank;
		int chunk_idx = rank / chunk_size;

		if (chunk_idx == 0)
			pb(a, b);
		else if (chunk_idx == 1)
		{
			pb(a, b);
			rb(a, b);
		}
		else
		{
			pb(a, b);
			rrb(a, b);
		}
	}
}


void	multiway_push_sort(t_list *a, t_list *b, int n_chunks)
{
	distribute_chunks(a, b, n_chunks);
	greedy_merge(a, b);

	// 🔹 passo final: gira A até o menor elemento ficar no topo
	int pos_min = find_position(a, 0);
	if (pos_min >= 0)
		rotate_to_top(a, b, pos_min, 'a');
}




char *to_base_string(int n, int max_len, int base)
{
    char *s = calloc(max_len + 1, sizeof(char));
    for (int i = max_len - 1; i >= 0; i--)
    {
        s[i] = '0' + (n % base);
        n /= base;
    }
    return s;
}
int base_len(int n, int base)
{
    return (int)ceil(log(n + 1) / log(base));
}
#include <string.h>
void radix_base2(t_list *a, t_list *b)
{
    if (!a || a->count < 2)
        return;


}

void radix_base3(t_list *a, t_list *b)
{
    if (!a || a->count < 2)
        return;

    int len = base_len(a->count, 3);

    t_node *n = a->first;
    while (n)
    {
        t_context *ctx = n->content;
        ctx->rank_string = to_base_string(ctx->rank, len, 3);
        n = n->next;
    }

    for (int i = len - 1; i >= 0; i--)
    {
        size_t count = a->count;
        for (size_t j = 0; j < count; j++)
        {
            t_context *ctx = a->first->content;
            char digit = ctx->rank_string[i];

            if (digit == '2')
				ra(a, b);
            else if (digit == '1')
				pb(a, b);
            else
            {
                pb(a, b);
                rb(a, b);
            }
        }


		count = b->count;
        for (size_t k = 0; k < count; k++)
        {
            t_context *ctx = b->first->content;
            char digit = ctx->rank_string[i];

            if (digit == '1')
				pa(a, b);
            else
            {
                rrb(a, b);
                pa(a, b);
            }
        }
    }
}


void radix_base4(t_list *a, t_list *b)
{
    if (!a || a->count < 2)
        return;

    int len = base_len(a->count, 4);

    t_node *n = a->first;
    while (n)
    {
        t_context *ctx = n->content;
        ctx->rank_string = to_base_string(ctx->rank, len, 4);
        n = n->next;
    }

    for (int i = len - 1; i >= 0; i--)
    {
        size_t count = a->count;
        for (size_t j = 0; j < count; j++)
        {
            t_context *ctx = a->first->content;
            char digit = ctx->rank_string[i];

            if (digit == '3')
				ra(a, b);
            else if (digit == '1' || digit == '2')
				pb(a, b);
            else
            {
                pb(a, b);
                rb(a, b);
            }
        }
		
		// print_stacks_base3(a, b);

		int reversed_1_count = 0;

		// 1️⃣ varre devolvendo 2, empurrando 1 para o fundo e parando ao encontrar 0
		count = b->count;
		while (count)
		{
			t_context *ctx = b->first->content;
			char digit = ctx->rank_string[i];

			if (digit == '0')
				break;

			if (digit == '2')
				pa(a, b);
			else
			{
				rb(a, b);              // empurra '1' pro fundo
				reversed_1_count++;
			}
			count--;
		}

		// 2️⃣ reverte as rotações dos '1'
		while (reversed_1_count--)
			rrb(a, b);

		// 3️⃣ devolve todos os '1' (agora em ordem correta)
		count = b->count;
		while (count--)
		{
			t_context *ctx = b->first->content;
			char digit = ctx->rank_string[i];

			if (digit == '1')
				pa(a, b);
			else
				rb(a, b);              // pula os '0'
		}

		// 4️⃣ agora devolve os '0' do fundo — só gira se realmente houver '0'
		while (b->count)
		{
			t_context *ctx = b->last->content;
			if (ctx->rank_string[i] == '0')
			{
				rrb(a, b);
				pa(a, b);
			}
			else
				break; // topo e fundo já limpos
		}

		// print_stacks_base3(a, b);
    }
}

