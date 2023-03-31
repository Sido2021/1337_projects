#include "../push_swap.h"

void print_stack_by_group(t_stack *stack , char *stack_name, int group)
{
  int i = 0;
  if(stack != NULL)
  {
    t_num *tmp = stack->top;
	int count = 0;
    printf("==== stack %s =====\n", stack_name);
    while(i < stack->count)
    {
      char c = ' ';
      if(tmp->need_swap)
        c = '*';
		if(tmp->group == group){
			if(tmp->previous != NULL && tmp->next != NULL)
				printf("%d[%d][%d]%c\t\tprev : %8d , \t\tnext : %8d\n", tmp->number, tmp->index, tmp->group, c, tmp->previous->number,tmp->next->number);
			else if(tmp->previous == NULL && tmp->next != NULL)
				printf("%d[%d][%d]%c\t\tprev : %8s , \t\tnext : %8d\n", tmp->number, tmp->index, tmp->group, c, "NULL",tmp->next->number);
			else if(tmp->previous != NULL && tmp->next == NULL)
				printf("%d[%d][%d]%c\t\tprev : %8d , \t\tnext : %8s\n", tmp->number, tmp->index, tmp->group, c, tmp->previous->number,"NULL");
			else
				printf("%d[%d][%d]%c\t\tprev : %s , \t\tnext : %8s\n", tmp->number, tmp->index, tmp->group, c, "NULL", "NULL");
			/*if(i == stack->count/2)
				printf("------------------------------------------------\n");*/
			count++;
		}
		i++;
		tmp = tmp->next;
    }
    printf("group count : %d\n", count);
    /*if(stack->count > 0)
    {
      t_num *smallest = get_smallest_number(stack);
      printf("stack %s first : %d\n", stack_name, stack->top->number);
      printf("stack %s last : %d\n", stack_name, stack->top->previous->number);
      printf("stack %s smallest : %d\n", stack_name, smallest->number);
    }*/
  }
}