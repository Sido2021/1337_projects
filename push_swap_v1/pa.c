#include "push_swap.h"

void  pa(t_stack *stack_from, t_stack *stack_to)
{
  t_num *num;
  if(stack_from && stack_from->count > 0 && stack_to && stack_from != stack_to)
  {
    num = stack_from->top;
    pop(stack_from);
    push(stack_to, num);
  }
  ft_putstr("pa\n");
}
