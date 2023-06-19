
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_num
{
  int  number;
  struct s_num  *next;
  struct s_num  *previous;
  int group;
  int need_swap;
  int sort_count;
  struct s_num *previous_sort;
  int index;
} t_num;

typedef struct s_num_wizard
{
  t_num *num;
  struct s_num_wizard *next;
  int count;
} t_num_wizard;

typedef struct s_stack
{
  t_num *top;
  t_num *sorted_head;
  int count;
} t_stack;

void  sa(t_stack *stack);
void  sb(t_stack *stack);
void  ft_putchr(char c);
void  ft_putstr(char *str);
void  ss(t_stack *stack_a, t_stack *stack_b);
void  pop(t_stack *stack);
void  push(t_stack *stack, t_num *num);
void  pa(t_stack *stack_from, t_stack *stack_to);
void  pb(t_stack *stack_from, t_stack *stack_to);
void  print_stack(t_stack *stack , char *stack_name);
void  print_stack_by_group(t_stack *stack , char *stack_name, int group);
void  ra(t_stack *stack);
void  rb(t_stack *stack);
void  swap(t_stack *stack);
void  rotate(t_stack *stack);
void  rr(t_stack *stack_a, t_stack *stack_b);
int   stack_contains_num(t_stack *stack, t_num *num);
void  reverse_rotate(t_stack *stack);
void  rra(t_stack *stack);
void  rrb(t_stack *stack);
void  rrr(t_stack *stack_a, t_stack *stack_b);
//t_num  *get_smallest_number(t_stack *stack);
t_stack *stack_dup(t_stack *stack);
t_num *num_dup(t_num *num);
int		load_best_sorted_list(t_stack *stack, int group);
void  sort_stack(t_stack *stack_a, t_stack *stack_b);

#endif
