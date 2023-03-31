#include "push_swap.h"

void  add_stack_to_array(t_stack *from_stack, t_stack *to_stack)
{
	t_num *tmp = from_stack->top;
	if(to_stack && from_stack)
	{
		while(tmp){
			if(stack_contains_num(to_stack, tmp)){
				push(to_stack, num_dup(tmp));
			}
			tmp = tmp->next;
			if(tmp->number ==from_stack->top->number)
				break;
		}
	}
}