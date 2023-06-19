#include "../push_swap.h"

int  stack_contains_num(t_stack *stack, t_num *num)
{
  int i = 0;
  if(stack == NULL)
    return (0);
  t_num *tmp = stack->top;
  
  while(i++ < stack->count)
  {
    if(tmp == num || tmp->number == num->number)
      return (1);
    tmp = tmp->next;
  }
  return (0);
}