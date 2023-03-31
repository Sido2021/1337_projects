#include "push_swap.h"

t_num *get_previous_sorted(t_num *num, int *p)
{
	num = num->previous;
	while(num->group != 1)
	{
		num = num->previous;
		(*p)++;
	}
	return num;
}

void start_the_magic(t_stack *stack_a, t_stack *stack_b, t_num *tmp, int op)
{
	while(stack_b->top != tmp)
	{
		if(op == 0)
			rb(stack_b);
		else
			rrb(stack_b);
	}
	if(tmp->number < stack_a->sorted_head->number)
		stack_a->sorted_head = tmp;
	tmp->group = 1;
	pa(stack_b, stack_a);
	//ra(stack_a);
	/*if(op == 0 || !stack_b->top)
	{
		tmp = stack_b->top;
	}
	else 
	{
		tmp = stack_b->top->previous;
	}*/
}

void check_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	t_num *tmp = stack_b->top;
	t_num *tmp_rev = NULL;
	if(stack_b->top)
		tmp_rev = stack_b->top->previous;
	int i = 1;
	while(tmp && tmp_rev)
	{
		t_num *prev = stack_a->top;
		int p = 0;
		int found = 0;
		printf("%d\n", p);
		while (!found)
		{
			prev = get_previous_sorted(prev, &p);
			if(p > 4)
				break;
			if((stack_a->top == stack_a->sorted_head && (tmp->number < stack_a->top->number || tmp->number > prev->number)) || ( stack_a->top != stack_a->sorted_head  && tmp->number < stack_a->top->number && tmp->number > prev->number))
			{
				t_num *top = stack_a->top;
				while(stack_a->top != prev)
					rra(stack_a);
				start_the_magic(stack_a, stack_b, tmp, 0);
				tmp = stack_b->top;
				if(stack_b->top)
					tmp_rev = stack_b->top->previous;
				while(stack_a->top != top)
					ra(stack_a);
				found = 1;
			}
			else if((stack_a->top == stack_a->sorted_head && (tmp_rev->number < stack_a->top->number || tmp_rev->number > prev->number)) || ( stack_a->top != stack_a->sorted_head  && tmp_rev->number < stack_a->top->number && tmp_rev->number > prev->number))
			{
				t_num *top = stack_a->top;
				while(stack_a->top != prev)
					rra(stack_a);
				start_the_magic(stack_a, stack_b, tmp_rev, 1);
				tmp = stack_b->top;
				if(stack_b->top)
					tmp_rev = stack_b->top->previous;
				while(stack_a->top != top)
					ra(stack_a);
				found = 1;
			}
		}
		if(!found)
		{
			tmp_rev = tmp_rev->previous;
			tmp = tmp->next;
			if(tmp == tmp_rev || tmp->previous == tmp_rev)
				break ;
			if(tmp == stack_b->top)
				break ;
		}
		i++;
		if(i > 16)
			break;
	}
	/*while(stack_b->top)
	{
		//t_num *prev = get_previous_sorted(tmp);
		if(stack_a->top->number > tmp->number)
		{
			while(stack_b->top != tmp)
			{
				rb(stack_b);
			}
			pb(stack_b, stack_a);
			tmp->group = 1;
			if(tmp->number < stack_a->sorted_head->number)
				stack_a->sorted_head = tmp;
			tmp = stack_b->top;
		} if(stack_a->top->number < tmp->number && stack_a->sorted_head == stack_a->top)
		{
			while(stack_b->top != tmp)
			{
				rb(stack_b);
			}
			pb(stack_b, stack_a);
			tmp->group = 1;
			if(tmp->number < stack_a->sorted_head->number)
				stack_a->sorted_head = tmp;
			tmp = stack_b->top;
		}
		else 
		{
			tmp = tmp->next;
			if(tmp == stack_b->top)
				break ;
		}
	}*/
}

void sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_num *head = NULL;
	int first_turn_done = 0;
	while(stack_a->top)
	{
		if(stack_a->top->group != 1)
			pb(stack_a, stack_b);
		else
		{
			check_stack_b(stack_a, stack_b);
			if(head == NULL)
				head = stack_a->top;
			/*if(stack_a->top->need_swap == 1)
			{
				rra(stack_a);
				sa(stack_a);
				ra(stack_a);
			}*/
			if(stack_b->count > 1)
				rr(stack_a, stack_b);
			else
				ra(stack_a);
		}
		if(stack_a->top == head)
		{
			first_turn_done = 1;
		}
		if(first_turn_done && stack_b->count == 0)
			break;
	}
}