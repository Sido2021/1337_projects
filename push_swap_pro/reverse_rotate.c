#include "push_swap.h"

void  reverse_rotate(t_stack *stack)
{
  if(stack && stack->count > 1)
    stack->top = stack->top->previous;
}