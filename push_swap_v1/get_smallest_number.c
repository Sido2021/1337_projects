#include "push_swap.h"

t_num  *get_smallest_number(t_stack *stack)
{
  t_num  *smallest = stack->top;
  t_num  *tmp_forward = stack->top;
  t_num  *tmp_back = stack->top->previous;
  
  int  i = 0; 
  while(i++ < stack->count/2)
  {
    if(smallest->number > tmp_forward->number)
      smallest = tmp_forward;
    if(smallest->number > tmp_back->number)
      smallest = tmp_back;
    
    tmp_forward = tmp_forward->next;
    tmp_back = tmp_back->previous;
  }
  return smallest;
}