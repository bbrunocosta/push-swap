#include "push_swap.h"

t_context	*new_ctx(int n)
{
	t_context	*ctx;

	ctx = calloc(1, sizeof(t_context));
	if (!ctx)
		return (NULL);
	ctx->number = n;
	return (ctx);
}
