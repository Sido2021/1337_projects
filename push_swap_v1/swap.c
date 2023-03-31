#include "push_swap.h"

void  swap(t_stack *stack)
{
  t_num *tmp1;
  t_num *tmp2;
  
  if(stack && stack->count > 1) 
  {
    
    tmp1 = stack->top;
    tmp2 = stack->top->next;
    pop(stack);
    pop(stack);
    push(stack, tmp1);
    push(stack, tmp2);
  }
}