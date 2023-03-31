#include "push_swap.h"

void  pop(t_stack *stack)
{
  if(stack && stack->count > 0)
  {
    stack->top->next->previous = stack->top->previous;
    stack->top->previous->next = stack->top->next;
    if(stack->count > 1)
      stack->top = stack->top->next;
    else
      stack->top = NULL;
    stack->count--;
  }
}