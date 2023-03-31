
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
t_num  *get_smallest_number(t_stack *stack);
t_stack *stack_dup(t_stack *stack);
t_num *num_dup(t_num *num);
//t_stack *get_best_sorted_list(t_stack *stack, t_num *head, t_num *parent, int part2, int top_process, int *selected_numbers, int position);
//t_stack *get_best_sorted_list(t_stack *stack, t_num *head, t_num *parent);
//t_stack *load_best_sorted_list(t_stack *stack);
int  load_best_sorted_list(t_stack *stack, int group);
void  sort_stack(t_stack *stack_a, t_stack *stack_b);
//void  load_best_sorted_list(int *arr, int count);
//void get_best_sorted_list(t_stack *stack);
//void  add_stack_to_stack(t_stack *to_stack, t_stack *from_stack);
//int  array_contains_num(int *array, int array_length, int number);
//t_num  *get_next_smallest_number(t_stack *stack, t_num *number, int same_stack);
//t_num  *get_biggest_num_1st_part(t_stack *stack);
//void  split_numbers_biggest_smallest(t_stack *stack_a, t_stack *stack_b, t_num *sep);
//int  get_num_position(t_stack *stack, t_num *num);
//void  move_num_to_top(t_stack *stack, t_num *num);
//t_num  *get_biggest_number(t_stack *stack);
//void  ft_sort(t_stack *stack_a, t_stack *stack_b);

#endif