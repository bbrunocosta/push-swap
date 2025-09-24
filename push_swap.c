#include "listft.h"

void pa(t_list *a, t_list *b)
{
	if (b->count)
		lst_push(a, lst_pop(b));
}
void pb(t_list *a, t_list *b)
{
	if (a->count)
		lst_push(b, lst_pop(a));
}
void sa(t_list *a, t_list *b)
{
	t_node *fisrt = lst_pop(a);
	t_node *second = lst_pop(a);
	if (fisrt)
		lst_push(a, fisrt);
	if (second)
		lst_push(a, second);
}
void sb(t_list *a, t_list *b)
{
	t_node *fisrt = lst_pop(b);
	t_node *second = lst_pop(b);
	if (fisrt)
		lst_push(b, fisrt);
	if (second)
		lst_push(b, second);
}
void ss(t_list *a, t_list *b)
{
	sa(a,b);
	sb(a,b);
}
void ra(t_list *a, t_list *b)
{
	if(a->count > 1)
	{
		t_node *node = lst_detach(a->first);
		lst_add_last(a, node);
	}
}

void rb(t_list *a, t_list *b)
{
	if(b->count > 1)
	{
		t_node *node = lst_detach(b->last);
		lst_push(b, node);
	}
}

void rr(t_list *a, t_list *b)
{
	ra(a,b);
	rb(a,b);
}
typedef enum
{
	INVALID_INSTRUCTION, PA, PB, SA, SB, SS, RA, RB, RR, INTRUCTION_COUNT
} e_instruction;

typedef void (*f_instruction)(t_list*,t_list*);

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	*new_number(int n)
{
	int	*number;

	number = calloc(1, sizeof(int));
	if (!number)
		return (NULL);
	*number = n;
	return (number);
}
#include <stdio.h>
#include <string.h>

void print_stacks(t_list *a, t_list *b)
{
    char buffer[10000];   // buffer grande o suficiente
    char line[128];       // linha temporária
    size_t offset = 0;

    t_node *na = a->first;
    t_node *nb = b->first;

    // clear screen
    offset += sprintf(buffer + offset, "\033[3J\033[H\033[2J");

    while (na || nb)
    {
        if (na && nb)
            offset += sprintf(buffer + offset, "%-5d %-5d\n",
                              *(int*)na->content, *(int*)nb->content);
        else if (na)
            offset += sprintf(buffer + offset, "%-5d\n", *(int*)na->content);
        else if (nb)
            offset += sprintf(buffer + offset, "      %-5d\n", *(int*)nb->content);

        if (na) na = na->next;
        if (nb) nb = nb->next;
    }

    offset += sprintf(buffer + offset, "A     B\n");

    // imprime tudo de uma vez
    printf("%s", buffer);
}

void main(void)
{
	t_list a = {0};
	lst_push(&a,lst_new_node(new_number(2)));
	lst_push(&a,lst_new_node(new_number(5)));
	lst_push(&a,lst_new_node(new_number(0)));
	lst_push(&a,lst_new_node(new_number(4)));
	lst_push(&a,lst_new_node(new_number(9)));
	lst_push(&a,lst_new_node(new_number(1)));
	lst_push(&a,lst_new_node(new_number(6)));
	lst_push(&a,lst_new_node(new_number(8)));
	lst_push(&a,lst_new_node(new_number(3)));
	lst_push(&a,lst_new_node(new_number(7)));
	t_list b = {0};
	f_instruction instruction_map[] = {
		pa, pb, sa, sb, ss, ra, rb, rr, NULL
	};

	do
	{
		print_stacks(&a, &b);
		int value;
		scanf("%d", &value);
		instruction_map[value](&a, &b);
	}
	while(1);

	lst_delete_all(&a, free);
	lst_delete_all(&b, free);

}