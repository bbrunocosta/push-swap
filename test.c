// #include "listft.h"
// #include <stdlib.h>
// #include <stdio.h>
// #include <math.h>

// /*
// ** ========================================
// **   Estruturas básicas e forward declarations
// ** ========================================
// */

// void pa(t_list *a, t_list *b);
// void pb(t_list *a, t_list *b);
// void sa(t_list *a, t_list *b);
// void rrr(t_list *a, t_list *b);
// void rr(t_list *a, t_list *b);
// void rrb(t_list *a, t_list *b);
// void rb(t_list *a, t_list *b);
// void rra(t_list *a, t_list *b);
// void ra(t_list *a, t_list *b);
// void ss(t_list *a, t_list *b);
// void sb(t_list *a, t_list *b);

// /*
// ** Cada nó da pilha contém um número e o "rank"
// ** — o rank representa a posição do número se estivesse ordenado.
// ** Exemplo:
// ** números = [42, -10, 99]
// ** ranks   = [1,   0,   2]
// **
// ** Isso permite que o algoritmo funcione independentemente do valor absoluto.
// */
// typedef struct s_context
// {
// 	int number;
// 	size_t rank;
// }	t_context;

// /*
// ** ========================================
// **   Utilitários básicos para manipulação
// ** ========================================
// */

// /*
// ** Encontra a posição (0-index) de um elemento com determinado rank na pilha.
// ** É usado para saber quantas rotações são necessárias para trazê-lo ao topo.
// */
// int	find_position(t_list *stack, int rank)
// {
// 	t_node *n = stack->first;
// 	int pos = 0;
// 	while (n)
// 	{
// 		if (((t_context*)n->content)->rank == rank)
// 			return (pos);
// 		n = n->next;
// 		pos++;
// 	}
// 	return (-1);
// }

// /*
// ** Determina onde um elemento de rank X deve ser inserido na pilha A
// ** para que a pilha continue ordenada (em ordem crescente).
// **
// ** A lógica considera o par (atual, próximo) e encontra o ponto
// ** onde o rank se encaixa entre eles.
// ** Caso não haja posição "perfeita", retorna a menor diferença.
// */
// int	find_insert_pos(t_list *a, int rank)
// {
// 	t_node *n = a->first;
// 	int pos = 0;
// 	int best_pos = 0;
// 	int min_gap = 2147483647;

// 	while (n)
// 	{
// 		int curr = ((t_context*)n->content)->rank;
// 		int next = (n->next) ? ((t_context*)n->next->content)->rank
// 							 : ((t_context*)a->first->content)->rank;

// 		// caso o rank caiba entre dois valores consecutivos
// 		if ((rank > curr && rank < next) ||
// 			(curr > next && (rank > curr || rank < next)))
// 		{
// 			best_pos = pos + 1;
// 			break;
// 		}

// 		// caso não, escolhe o ponto mais próximo (por diferença de rank)
// 		int gap = abs(rank - curr);
// 		if (gap < min_gap)
// 		{
// 			min_gap = gap;
// 			best_pos = pos + 1;
// 		}

// 		n = n->next;
// 		pos++;
// 	}
// 	return (best_pos % a->count);
// }

// /*
// ** Gira uma pilha até que o elemento desejado esteja no topo.
// ** A direção (ra vs rra) é escolhida conforme o lado mais curto.
// **
// ** stack = 'a' ou 'b' -> determina qual função de rotação usar.
// */
// void	rotate_to_top(t_list *a, t_list *b, int pos, char stack)
// {
// 	int size = (stack == 'a') ? a->count : b->count;

// 	while (pos != 0)
// 	{
// 		if (pos <= size / 2) // mais rápido girar pra frente
// 		{
// 			if (stack == 'a')
// 				ra(a, b);
// 			else
// 				rb(a, b);
// 			pos--;
// 		}
// 		else // mais rápido girar pra trás
// 		{
// 			if (stack == 'a')
// 				rra(a, b);
// 			else
// 				rrb(a, b);
// 			pos = (pos + 1) % size;
// 		}
// 	}
// }

// /*
// ** ========================================
// **   Estruturas auxiliares para o modo greedy
// ** ========================================
// */

// typedef struct s_move
// {
// 	int rank;   // rank do elemento a mover
// 	int pos_a;  // posição onde deve ser inserido em A
// 	int pos_b;  // posição atual em B
// 	int cost;   // custo total da operação
// 	int dir_a;  // direção da rotação de A (1 = ra, -1 = rra)
// 	int dir_b;  // direção da rotação de B (1 = rb, -1 = rrb)
// }	t_move;


// // ** Calcula o custo de mover um elemento de rank específico de B → A.
// // **
// // ** - Determina quantas rotações são necessárias em cada pilha.
// // ** - Se ambas as pilhas giram no mesmo sentido, podemos usar rr/rrr.
// // ** - O custo final é o máximo ent**
