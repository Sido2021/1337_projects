#include "push_swap.h"

t_stack *stack_dup(t_stack *stack)
{
	t_stack *s = malloc(sizeof(t_stack));
	t_num *tmp = stack->top;
	t_num *t = NULL;
	while(s->top == NULL || tmp->number != stack->top->number){
		t_num *n = malloc(sizeof(t_num));
		n->number = tmp->number;
		if(s->top == NULL)
		{
			s->top = n;
		}
		else
		{
			t->next = n;
			n->previous = t;
		}
		n->next = s->top;
		s->top->previous = n;
		tmp = tmp->next;
		t = n;
		s->count++;
	}
	return (s);
}