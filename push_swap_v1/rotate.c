#include "push_swap.h"

void  rotate(t_stack *stack)
{
  if(stack && stack->count > 1)
    stack->top = stack->top->next;
}