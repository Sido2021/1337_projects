#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}

int get_index(int *arr, int number, int length){
  int i = -1;
  while(++i < length)
  {
    if(arr[i] == number)
      return (i);
  }

  return (-1);
}

long	ft_atoi(const char *str, int *status)
{
	long	num;
	long	sign;

	num = 0;
	sign = 1;
	if(status != NULL)
		*status = 0;
	while ((*str < 14 && *str > 8) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str)
	{
		if(status != NULL)
			*status = 0;
		if(ft_isdigit(*str)) {
			num = num * 10 + (*str++ - 48);
			if(status != NULL)
				*status = 1;
		}
		else {
			break ;
		}
	}
	return (num * sign);
}

void add_number_to_stack(t_stack *stack, int num) {
    t_num *tmp;

    tmp = (t_num *) malloc(sizeof(t_num));
	tmp->group = 0;
	tmp->number = num;
    if(stack->top == NULL) {
       stack->top = tmp;
	   stack->top->next = tmp;
	   stack->top->previous = tmp;
    }
    else {
        tmp->previous = stack->top->previous;
        tmp->next = stack->top;
		stack->top->previous->next = tmp;
		stack->top->previous = tmp;
    }
    stack->count++;
}

int check_args(int ac, char **av, t_stack *stack) {
	int i;
	int j;
	long num;
	int status;
	long num2;

	i = 1;
	if(ac < 2) {
		return 0;
	}
	else {
		while(i < ac)
		{
			num = ft_atoi(av[i], &status);
			if(status && num >= -2147483648 && num <= 2147483647)
			{
				j = i + 1;
				while(j < ac) {
					num2 = ft_atoi(av[j], &status);
					if(!status || num2 < -2147483648 || num2 > 2147483647 || num2 == num) {
						return (2);
					}
					j++;
				}
				add_number_to_stack(stack, num);
			}
			else {
				return (2);
			}
			i++;
		}
		return (1);
	}
}

int main(int ac, char **av) {
	t_stack stack_a;
	t_stack stack_b;
	stack_a.top = NULL;
	stack_a.count = 0;
	stack_b.top = NULL;
	stack_b.count = 0;


	int status = check_args(ac, av, &stack_a);
	if(status == 0) {
		return (0);
	}
	else if(status == 2)
		write(2, "Error\n", 6);
	else {
		load_best_sorted_list(&stack_a, 1);
		sort_stack(&stack_a, &stack_b);
		//print_stack(&stack_a, "a");
	}
 }
