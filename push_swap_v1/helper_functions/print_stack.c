#include "../push_swap.h"

void print_stack(t_stack *stack , char *stack_name)
{
  int i = 0;
  if(stack != NULL)
  {
    t_num *tmp = stack->top;

    printf("==== stack %s =====\n", stack_name);
    printf("count : %d\n", stack->count);
    while(i < stack->count)
    {
      char c = ' ';
      if(tmp->need_swap)
        c = '*';
      if(tmp->previous != NULL && tmp->next != NULL)
        printf("%d[%d][%d]%c\t\tprev : %8d , \t\tnext : %8d\n", tmp->number, tmp->index, tmp->group, c, tmp->previous->number,tmp->next->number);
      else if(tmp->previous == NULL && tmp->next != NULL)
      printf("%d[%d][%d]%c\t\tprev : %8s , \t\tnext : %8d\n", tmp->number, tmp->index, tmp->group, c, "NULL",tmp->next->number);
      else if(tmp->previous != NULL && tmp->next == NULL)
        printf("%d[%d][%d]%c\t\tprev : %8d , \t\tnext : %8s\n", tmp->number, tmp->index, tmp->group, c, tmp->previous->number,"NULL");
      else
        printf("%d[%d][%d]%c\t\tprev : %s , \t\tnext : %8s\n", tmp->number, tmp->index, tmp->group, c, "NULL", "NULL");
      tmp = tmp->next;
      i++;
      if(i == stack->count/2)
        printf("------------------------------------------------\n");
    }
    if(stack->count > 0)
    {
      t_num *smallest = get_smallest_number(stack);
      printf("stack %s first : %d\n", stack_name, stack->top->number);
      printf("stack %s last : %d\n", stack_name, stack->top->previous->number);
      printf("stack %s smallest : %d\n", stack_name, smallest->number);
    }
  }
}