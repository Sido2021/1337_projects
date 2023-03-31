#include "push_swap.h"

t_num *num_dup(t_num *num)
{
	if(num == NULL)
		return NULL;
	t_num *n = malloc(sizeof(t_num));
	n->number = num->number;
	return (n);
}