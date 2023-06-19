#include "push_swap.h"

void  push(t_stack *stack, t_num *num)
{
  if(stack && stack->top != num)
  {
    if(stack->count > 0)
    {
      num->next = stack->top;
      num->previous = stack->top->previous;
      
      stack->top->previous->next = num;
      stack->top->previous = num;
      stack->top = num;
    }
    else
    {
      stack->top = num;
      stack->top->next = num;
      stack->top->previous = num;
    }
    stack->count++;
  }
}