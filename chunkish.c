#include "listft.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


/*
** ========================================
**   Estruturas básicas e forward declarations
** ========================================
*/


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



typedef struct s_context
{
	int number;
	size_t rank;
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

void radix_base4(t_list *a, t_list *b)
{
    int max_rank = a->count - 1;
    int digits = 0;

    while ((max_rank >> (2 * digits)) != 0)
        digits++;

    for (int d = 0; d < digits; d++)
    {
        int size = a->count;
        for (int j = 0; j < size; j++)
        {
            int rank = ((t_context*)a->first->content)->rank;
            int digit = (rank >> (2 * d)) & 0b11; // 0..3

            if (digit == 0)
                pb(a, b);              // bucket 0 → B
            else
                ra(a, b);              // mantém em A (temporariamente)
        }

        // 1️⃣ devolve bucket 0 (os com digit==0)
        while (b->count)
            pa(a, b);

        // 2️⃣ segunda varredura: bucket 1
        size = a->count;
        for (int j = 0; j < size; j++)
        {
            int rank = ((t_context*)a->first->content)->rank;
            int digit = (rank >> (2 * d)) & 0b11;
            if (digit == 1)
                pb(a, b);
            else
                ra(a, b);
        }
        while (b->count)
            pa(a, b);

        // 3️⃣ bucket 2
        size = a->count;
        for (int j = 0; j < size; j++)
        {
            int rank = ((t_context*)a->first->content)->rank;
            int digit = (rank >> (2 * d)) & 0b11;
            if (digit == 2)
                pb(a, b);
            else
                ra(a, b);
        }
        while (b->count)
            pa(a, b);

        // 4️⃣ bucket 3
        size = a->count;
        for (int j = 0; j < size; j++)
        {
            int rank = ((t_context*)a->first->content)->rank;
            int digit = (rank >> (2 * d)) & 0b11;
            if (digit == 3)
                pb(a, b);
            else
                ra(a, b);
        }
        while (b->count)
            pa(a, b);
    }
}


// void radix_base4(t_list *a, t_list *b)
// {
//     int max_bits = 0;
//     int max_rank = a->count - 1;

//     // calcula quantos dígitos base 4 (2 bits) são necessários
//     while ((max_rank >> (2 * max_bits)) != 0)
//         max_bits++;

//     for (int i = 0; i < max_bits; i++)
//     {
//         size_t count = a->count;
//         for (size_t j = 0; j < count; j++)
//         {
//             int rank = ((t_context*)a->first->content)->rank;
//             int digit = (rank >> (2 * i)) & 0b11; // extrai 2 bits

//             if (digit == 0)
//                 ra(a, b);
//             else if (digit == 1)
//                 pb(a, b);
//             else if (digit == 2)
//                 rb(a, b);
//             else if (digit == 3)
//                 rrb(a, b);
//         }

//         // depois de processar os 4 grupos, retorna todos para A
//         while (b->count > 0)
//             pa(a, b);
//     }

//     // garante que o menor valor (rank 0) fique no topo
//     int pos_min = find_position(a, 0);
//     if (pos_min >= 0)
//         rotate_to_top(a, b, pos_min, 'a');
// }
