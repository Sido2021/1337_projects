#include "push_swap.h"

/*t_stack *get_best_sorted_list(t_stack *stack, t_num *head, t_num *parent, int part2, int top_process, int * selected_numbers, int position)
{
	t_stack *best = NULL;
	t_num *tmp = NULL;
	if(top_process && !part2)
	{
		tmp = head;
		position = 0;
	}
	else if(top_process && part2){
		tmp = parent;
	}
	else
	{
		tmp = parent->next;
	}


	while(tmp)
	{
		if(!top_process && tmp->number == head->number){
			break ;
		}
			t_stack *s = NULL;
			if((!part2 && top_process) || (part2 && top_process && tmp->number < head->number)){
				//int num_selected = stack_contains_num(selected_numbers, tmp);
				int count = 0;
				if(best != NULL) count = best->count;
				int num_selected = array_contains_num(selected_numbers, count, tmp->number);
				if(!num_selected){
					if(!part2)
						s = get_best_sorted_list(stack, tmp, tmp, part2, 0, selected_numbers, position+1);
					else
						s = get_best_sorted_list(stack, head, tmp, part2, 0,selected_numbers, position+1);
					if(best == NULL || best->count < s->count)
					{
						best = s;
						selected_numbers[position] = tmp->number;
					}
				}
			}
			else if((!part2 && tmp->number > parent->number) || (part2 && tmp->number > parent->number && tmp->number < head->number)){
				//int num_selected = stack_contains_num(selected_numbers, tmp);
				int count = 0;
				if(best != NULL) count = best->count;
				int num_selected = array_contains_num(selected_numbers, count, tmp->number);
				if(!num_selected){
					s = get_best_sorted_list(stack, head, tmp, part2, 0, selected_numbers, position+1);
					if(best == NULL || best->count < s->count)
					{
						best = s;
						if(!top_process){
							push(best, num_dup(tmp));
						}
						selected_numbers[position] = tmp->number;
						//add_stack_to_stack(selected_numbers, best);
					}
				}
				
			}
		
		tmp = tmp->next;
		if(tmp->number == head->number){
			break;
		}
	}
	if(part2){
		if(best == NULL)
			best = malloc(sizeof(t_stack));
	}
	else if(best == NULL){
		best = get_best_sorted_list(stack, head, parent->next, 1, 1, selected_numbers, position+1);
	}
	return best;
}*/


/*int array_contains_num(int *selected_numbers,int length, int num, int position)
{
	if(selected_numbers == NULL || length < 1 || position == length/2 + length%2)
		return (0);
	if(selected_numbers[position] == num || selected_numbers[length - position - 1] == num)
		return (1);
	else
		return array_contains_num(selected_numbers, length, num, position+1);
}

void	add_stack_to_array(t_stack *stack, int *array, int *length){
	
	t_num *tmp = stack->top;
	while(tmp){
		if(!array_contains_num(array, *length, tmp->number, 0)){
			array[*length] = tmp->number;
			(*length)++;
		}
		tmp = tmp->next;
		if(tmp->number == stack->top->number)
			break ;
	}
}

t_stack *get_best(t_stack *stack, t_num *head, t_num *parent)
{
	t_stack *best = NULL;
	t_num *tmp = NULL;
	int selected_numbers[stack->count];
	tmp = parent->next;
	int length = 0;
	while(tmp->number != head->number){
		int count = 0;
		if(best != NULL) count = best->count;
		int num_selected = array_contains_num(selected_numbers, count , tmp->number, 0);
		if(!num_selected){
			if(tmp->number > parent->number){
				t_stack *s = get_best(stack, head, tmp);
				if(best == NULL || best->count < s->count)
				{
					best = s;
					push(best, num_dup(tmp));
					add_stack_to_array(best, selected_numbers, &length);
				}
			}
		}
		tmp = tmp->next;
	}
	if(best == NULL){
		best = malloc(sizeof(t_stack));
	}
	return best;
}

t_stack *get_best_sorted_list(t_stack *stack)
{
	t_stack *best = NULL;
	t_num *tmp = stack->top;
	int selected_numbers[stack->count];
	int length = 0;
	while(tmp){
		t_stack *s = get_best(stack, tmp, tmp);
		int count = 0;
		if(best != NULL) count = best->count;
		int num_selected = array_contains_num(selected_numbers, count , tmp->number, 0);
		if(!num_selected){
			if(best == NULL || best->count < s->count)
			{
				best = s;
				push(best, num_dup(tmp));
				add_stack_to_array(best, selected_numbers, &length);
			}
		}
		tmp = tmp->next;
		if(tmp->number == stack->top->number){
			break ;
		}
	}
	return best;
}*/

//V3
/*int array_contains_num(int *selected_numbers,int length, int num, int position)
{
	if(selected_numbers == NULL || length < 1 || position == length/2 + length%2)
		return (0);
	if(selected_numbers[position] == num || selected_numbers[length - position - 1] == num)
		return (1);
	else
		return array_contains_num(selected_numbers, length, num, position+1);
}

void	add_stack_to_array(t_stack *stack, int *array, int *length){
	
	t_num *tmp = stack->top;
	while(tmp){
		if(!array_contains_num(array, *length, tmp->number, 0)){
			array[*length] = tmp->number;
			(*length)++;
		}
		tmp = tmp->next;
		if(tmp->number == stack->top->number)
			break ;
	}
}

t_num	*get_num_by_index(t_stack *stack, int index){
	
	t_num *tmp = stack->top;
	while(tmp){
		if(tmp->index == index){
			return tmp;
		}
		tmp = tmp->next;
		if(tmp->number == stack->top->number)
			break ;
	}
	return NULL;
}

t_stack *get_best(t_stack *stack, t_num *head, t_num *parent)
{
	t_stack *best = NULL;
	t_num *tmp = NULL;
	int selected_numbers[stack->count];
	tmp = parent->next;
	int length = 0;
	while(tmp->number != head->number){
		int count = 0;
		if(best != NULL) count = best->count;
		int num_selected = array_contains_num(selected_numbers, count , tmp->number, 0);
		if(!num_selected){
			if(tmp->number > parent->number){
				t_stack *s = get_best(stack, head, tmp);
				if(best == NULL || best->count < s->count)
				{
					best = s;
					push(best, num_dup(tmp));
				}
				add_stack_to_array(best, selected_numbers, &length);
			}
		}
		tmp = tmp->next;
	}
	if(best == NULL){
		best = malloc(sizeof(t_stack));
	}
	return best;
}

t_stack *get_best_sorted_list(t_stack *stack)
{
	t_stack *best = NULL;
	t_num *tmp = stack->top;
	int selected_numbers[stack->count];
	int length = 0;
	int i = -1;
	while(++i < stack->count/2 + stack->count%2){
		tmp = get_num_by_index(stack, i);
		int count = 0;
		if(best != NULL) count = best->count;
		int num_selected = array_contains_num(selected_numbers, count , tmp->number, 0);
		if(!num_selected){
			t_stack *s = get_best(stack, tmp, tmp);
			if(best == NULL || best->count < s->count)
			{
				best = s;
				push(best, num_dup(tmp));
				add_stack_to_array(best, selected_numbers, &length);
			}
		}
	}
	return best;
}*/





//V4
/*int array_contains_num(int *selected_numbers,int length, int num, int position)
{
	if(selected_numbers == NULL || length < 1 || position == length/2 + length%2)
		return (0);
	if(selected_numbers[position] == num || selected_numbers[length - position - 1] == num)
		return (1);
	else
		return array_contains_num(selected_numbers, length, num, position+1);
}

void	add_stack_to_array(t_stack *stack, int *array, int *length){
	
	t_num *tmp = stack->top;
	while(tmp){
		if(!array_contains_num(array, *length, tmp->number, 0)){
			array[*length] = tmp->number;
			(*length)++;
		}
		tmp = tmp->next;
		if(tmp->number == stack->top->number)
			break ;
	}
}

t_num	*get_num_by_index(t_stack *stack, int index){
	
	t_num *tmp = stack->top;
	while(tmp){
		if(tmp->index == index){
			return tmp;
		}
		tmp = tmp->next;
		if(tmp->number == stack->top->number)
			break ;
	}
	return NULL;
}

void load_swapped_numbers(t_stack *origin, t_stack *target)
{
	if(origin && target){
		t_num *tmp = origin->top;
		t_num *tmp2 = target->top;
		while(tmp){
			if(tmp->number == tmp2->next->number){
				tmp2 = tmp2->next;
			}
			else if(tmp->number > tmp2->previous->number && tmp->number < tmp2->number){
				t_num *n =  num_dup(tmp);
				n->need_swap = 1;
				n->next = tmp2;
				n->previous = tmp2->previous;
				tmp2->previous = n;
				n->previous->next = n;
				target->count++;
			}
			tmp = tmp->next;
			if(tmp->number == origin->top->number)
				break ;
		}
	}
}

t_stack *get_best(t_stack *stack, t_num *head, t_num *parent)
{
	t_stack *best = NULL;
	t_num *tmp = NULL;
	int selected_numbers[stack->count];
	tmp = parent->next;
	int length = 0;
	while(tmp->number != head->number){
		int count = 0;
		if(best != NULL) count = best->count;
		int num_selected = array_contains_num(selected_numbers, count , tmp->number, 0);
		if(!num_selected){
			if(tmp->number > parent->number){
				t_stack *s = get_best(stack, head, tmp);
				if(best == NULL || best->count < s->count)
				{
					best = s;
					push(best, num_dup(tmp));
				}
				add_stack_to_array(best, selected_numbers, &length);
			}
		}
		tmp = tmp->next;
	}
	if(best == NULL){
		best = malloc(sizeof(t_stack));
	}
	return best;
}

t_stack *load_best_sorted_list(t_stack *stack)
{
	t_stack *best = NULL;
	t_num *tmp = stack->top;
	int selected_numbers[stack->count];
	int length = 0;
	int i = -1;
	while(++i < stack->count){
		tmp = get_num_by_index(stack, i);
		int count = 0;
		if(best != NULL) count = best->count;
		int num_selected = array_contains_num(selected_numbers, count , tmp->number, 0);
		if(!num_selected){
			t_stack *s = get_best(stack, tmp, tmp);
			if(best == NULL || best->count < s->count)
			{
				best = s;
				push(best, num_dup(tmp));
				load_swapped_numbers(stack, best);
			}
			add_stack_to_array(best, selected_numbers, &length);
		}
	}
	return best;
}*/


//V5
/*int array_contains_num(int *selected_numbers,int length, int num, int position)
{
	if(selected_numbers == NULL || length < 1 || position == length/2 + length%2)
		return (0);
	if(selected_numbers[position] == num || selected_numbers[length - position - 1] == num)
		return (1);
	else
		return array_contains_num(selected_numbers, length, num, position+1);
}

void	add_stack_to_array(t_stack *stack, int *array, int *length){
	
	t_num *tmp = stack->top;
	while(tmp){
		if(!array_contains_num(array, *length, tmp->number, 0)){
			array[*length] = tmp->number;
			(*length)++;
		}
		tmp = tmp->next;
		if(tmp->number == stack->top->number)
			break ;
	}
}

t_num	*get_num_by_index(t_stack *stack, int index){
	
	t_num *tmp = stack->top;
	while(tmp){
		if(tmp->index == index){
			return tmp;
		}
		tmp = tmp->next;
		if(tmp->number == stack->top->number)
			break ;
	}
	return NULL;
}

void load_swapped_numbers(t_stack *origin, t_stack *target)
{
	if(origin && target){
		t_num *tmp = origin->top;
		t_num *tmp2 = target->top;
		while(tmp){
			if(tmp->number == tmp2->next->number){
				tmp2 = tmp2->next;
			}
			else if(tmp->number > tmp2->previous->number && tmp->number < tmp2->number){
				
			}
			tmp = tmp->next;
			if(tmp->number == origin->top->number)
				break ;
		}
	}
}

void change_numbers_to_group(t_num *start, t_num *end ,int from_group, int to_group){
	while(start){
		if(start->group == from_group){
			start->group = to_group;
		}
		start = start->next;
		if(start->number == end->number)
			break ;
	}
}

void change_numbers_to_group_helper(t_num *start, t_num *end ,int from_group, int to_group){
	while(start){
		if(start->group_helper == from_group){
			start->group_helper = to_group;
		}
		start = start->next;
		if(start->number == end->number)
			break ;
	}
}

void confirm_group(t_num *start, t_num *end){
	while(start){
		if(start->group_helper == -1){
			start->group_helper = 0;
			start->group_helper = 1;
		}
		start = start->next;
		if(start->number == end->number)
			break ;
	}
}

t_num_wizard *load_best(t_stack *stack, t_num *head, t_num *parent)
{
	t_num *tmp = NULL;
	tmp = parent->next;
	t_num_wizard *best = malloc(sizeof(t_num_wizard));
	int current_count = 0;
	best->num = parent;
	best->count = 1;
	best->next = NULL;

	while(tmp->number != head->number){
		if(tmp->number > parent->number)
		{
			t_num_wizard *s = load_best(stack, head, tmp);
			if(s->count > current_count)
			{
				best->next = s;
				best->count = s->count + 1;
				current_count = s->count;
			}
		}
		tmp = tmp->next;
	}
	return best;
}

void load_best_sorted_list(t_stack *stack)
{
	t_num *tmp = stack->top;
	int i = -1;
	int current_count = 0;
	t_num_wizard *best;
	while(++i < stack->count){
		tmp = get_num_by_index(stack, i);
		t_num_wizard *s = load_best(stack, tmp, tmp);
		if(s->count > current_count)
		{
			best = s;
			current_count = s->count;
		}
	}
	printf("============ count : %d ==========\n", best->count);
	t_num_wizard *tmp2 = best;
	while(tmp2->next != NULL)
	{
		printf("%d\n", tmp2->num->number);
		tmp2 = tmp2->next;
	}
}*/

//V6
/*int array_contains_num(int *selected_numbers,int length, int num, int position)
{
	if(selected_numbers == NULL || length < 1 || position == length/2 + length%2)
		return (0);
	if(selected_numbers[position] == num || selected_numbers[length - position - 1] == num)
		return (1);
	else
		return array_contains_num(selected_numbers, length, num, position+1);
}

void	add_stack_to_array(t_stack *stack, int *array, int *length){
	
	t_num *tmp = stack->top;
	while(tmp){
		if(!array_contains_num(array, *length, tmp->number, 0)){
			array[*length] = tmp->number;
			(*length)++;
		}
		tmp = tmp->next;
		if(tmp->number == stack->top->number)
			break ;
	}
}

t_num	*get_num_by_index(t_stack *stack, int index){
	
	t_num *tmp = stack->top;
	while(tmp){
		if(tmp->index == index){
			return tmp;
		}
		tmp = tmp->next;
		if(tmp->number == stack->top->number)
			break ;
	}
	return NULL;
}

void load_swapped_numbers(t_stack *origin, t_stack *target)
{
	if(origin && target){
		t_num *tmp = origin->top;
		t_num *tmp2 = target->top;
		while(tmp){
			if(tmp->number == tmp2->next->number){
				tmp2 = tmp2->next;
			}
			else if(tmp->number > tmp2->previous->number && tmp->number < tmp2->number){
				
			}
			tmp = tmp->next;
			if(tmp->number == origin->top->number)
				break ;
		}
	}
}

void change_numbers_to_group(t_num *start, t_num *end ,int from_group, int to_group){
	while(start){
		if(start->group == from_group){
			start->group = to_group;
		}
		start = start->next;
		if(start->number == end->number)
			break ;
	}
}

void change_numbers_to_group_helper(t_num *start, t_num *end ,int from_group, int to_group){
	while(start){
		if(start->group_helper == from_group){
			start->group_helper = to_group;
		}
		start = start->next;
		if(start->number == end->number)
			break ;
	}
}

void confirm_group(t_num *start, t_num *end){
	while(start){
		if(start->group_helper == -1){
			start->group_helper = 0;
			start->group_helper = 1;
		}
		start = start->next;
		if(start->number == end->number)
			break ;
	}
}

int load_best(t_stack *stack, t_num *head, t_num *parent, t_num *best, int layer)
{
	t_num *tmp = NULL;
	tmp = parent->next;
	t_num arr[stack->count];
	int current_count = 0;

	while(tmp->number != head->number)
	{
		if(tmp->number > parent->number)
		{
			int count = load_best(stack, head, tmp, arr, layer+1);
			if(count > current_count)
			{
				count = current_count;
				int j = layer + 1;
				while(j < count)
				{
					best[j] = arr[j];
					j++;
				}
			}
		}
		tmp = tmp->next;
	}
	return current_count + 1;
}

void load_best_sorted_list(t_stack *stack)
{
	t_num *tmp = stack->top;
	int i = -1;
	int current_count = 0;
	t_num best[stack->count];
	int layer = 0;
	while(++i < stack->count){
		tmp = get_num_by_index(stack, i);
		int count = load_best(stack, tmp, tmp, best, layer + 1);
		if(count > current_count)
		{
			best[layer] = *tmp;
			current_count = count;
		}
	}
}*/


//V7
/*void load_best_sorted_list(int *arr, int count)
{
	int i = 0;
	int indexes[count];
	//int best[count];
	int collector[count];
	int layer = 0;
	int k = 0;
	while(i < count)
		indexes[i++] = 0;

	int previous;
	int current;
	while(indexes[0] < count)
	{
		collector[layer] = arr[k];
		
		indexes[count - 1]++;
		
		i = 0;
		while(i < count)
		{
			printf("%d,",indexes[i]);
			i++;
		}
		printf("\n===============\n");
		
		i = 0;
		int reset = 0;
		while(i < count)
		{
			if(!reset)
			{
				if(indexes[i] >= count - i)
				{
					indexes[i - 1]++;
					indexes[i] = 0;
					reset = 1;
				}
			}
			else
			{
				indexes[i] = 0;
			}
			i++;
		}
	}
}*/




//V6
/*int array_contains_num(int *selected_numbers,int length, int num, int position)
{
	if(selected_numbers == NULL || length < 1 || position == length/2 + length%2)
		return (0);
	if(selected_numbers[position] == num || selected_numbers[length - position - 1] == num)
		return (1);
	else
		return array_contains_num(selected_numbers, length, num, position+1);
}

void	add_stack_to_array(t_stack *stack, int *array, int *length){
	
	t_num *tmp = stack->top;
	while(tmp){
		if(!array_contains_num(array, *length, tmp->number, 0)){
			array[*length] = tmp->number;
			(*length)++;
		}
		tmp = tmp->next;
		if(tmp->number == stack->top->number)
			break ;
	}
}

t_num	*get_num_by_index(t_stack *stack, int index){
	
	t_num *tmp = stack->top;
	while(tmp){
		if(tmp->index == index){
			return tmp;
		}
		tmp = tmp->next;
		if(tmp->number == stack->top->number)
			break ;
	}
	return NULL;
}

void load_swapped_numbers(t_stack *origin, t_stack *target)
{
	if(origin && target){
		t_num *tmp = origin->top;
		t_num *tmp2 = target->top;
		while(tmp){
			if(tmp->number == tmp2->next->number){
				tmp2 = tmp2->next;
			}
			else if(tmp->number > tmp2->previous->number && tmp->number < tmp2->number){
				
			}
			tmp = tmp->next;
			if(tmp->number == origin->top->number)
				break ;
		}
	}
}

void change_numbers_to_group(t_num *start, t_num *end ,int from_group, int to_group){
	while(start){
		if(start->group == from_group)
		{
			start->group = to_group;
		}
		start = start->next;
		if(start->number == end->number)
			break ;
	}
}

int load_best(t_stack *stack, t_num *head, t_num *parent, int *best, int collection_count, int *best_count, int layer)
{
	t_num *tmp = NULL;
	tmp = parent->next;
	int smallest = tmp->number;
	int count = 0;
	int best_count_changed = 0;
	int current_count = *best_count;

	while(tmp->number != head->number)
	{
		if(tmp->number > parent->number)
		{
			smallest = tmp->number;
			int c = load_best(stack, head, tmp, best, collection_count + 1, best_count, layer);
			if(c + 1 + collection_count > current_count)
			{
				//change_numbers_to_group(head, tmp, layer, 0);
				//tmp->group = layer;
				best[collection_count] = tmp->number;
				*best_count = c + 1 + collection_count;
				best_count_changed = 1;
				current_count = *best_count;
				count = c;
			}
		}
		tmp = tmp->next;
	}
	if(best_count_changed)
	{
		//parent->group = layer;
		best[collection_count - 1] = tmp->number;
	}
	return ++count;
}

void load_best_sorted_list(t_stack *stack)
{
	t_num *tmp = stack->top;
	int i = -1;
	int best_count = 0;
	int layer = 0;
	int best[stack->count];
	//t_num *best;
	//int layer = 0;
	while(++i < stack->count)
	{
		tmp = get_num_by_index(stack, i);
		if(tmp->group == 0)
			load_best(stack, tmp, tmp, best, 1, &best_count, ++layer);
	}

	i = -1;
	while(++i < best_count)
	{
		printf("%d\n", best[i]);
	}
}*/


//V9
/*int array_contains_num(int *selected_numbers,int length, int num, int position)
{
	if(selected_numbers == NULL || length < 1 || position == length/2 + length%2)
		return (0);
	if(selected_numbers[position] == num || selected_numbers[length - position - 1] == num)
		return (1);
	else
		return array_contains_num(selected_numbers, length, num, position+1);
}

void	add_stack_to_array(t_stack *stack, int *array, int *length){
	
	t_num *tmp = stack->top;
	while(tmp){
		if(!array_contains_num(array, *length, tmp->number, 0)){
			array[*length] = tmp->number;
			(*length)++;
		}
		tmp = tmp->next;
		if(tmp->number == stack->top->number)
			break ;
	}
}

t_num	*get_num_by_index(t_stack *stack, int index){
	
	t_num *tmp = stack->top;
	while(tmp){
		if(tmp->index == index){
			return tmp;
		}
		tmp = tmp->next;
		if(tmp->number == stack->top->number)
			break ;
	}
	return NULL;
}

void load_swapped_numbers(t_stack *origin, t_stack *target)
{
	if(origin && target){
		t_num *tmp = origin->top;
		t_num *tmp2 = target->top;
		while(tmp){
			if(tmp->number == tmp2->next->number){
				tmp2 = tmp2->next;
			}
			else if(tmp->number > tmp2->previous->number && tmp->number < tmp2->number){
				
			}
			tmp = tmp->next;
			if(tmp->number == origin->top->number)
				break ;
		}
	}
}

void change_numbers_to_group(t_num *start, t_num *end ,int from_group, int to_group){
	while(start){
		if(start->group == from_group)
		{
			start->group = to_group;
		}
		start = start->next;
		if(start->number == end->number)
			break ;
	}
}

int load_best(int *arr, int arr_count, int head, int parent, int *best, int collection_count, int *best_count, int layer)
{
	int count = 0;
	int best_count_changed = 0;
	int current_count = *best_count;

	int index = parent + 1;
	if(index >= arr_count)
		index = 0;

	//int smallest = arr[index];
	while(index != head)
	{
		if(arr[index] > arr[parent])
		{
			//smallest = arr[index];
			int c = load_best(arr, arr_count, head, index, best, collection_count + 1, best_count, layer);
			if(c + 1 + collection_count > current_count)
			{
				//change_numbers_to_group(head, tmp, layer, 0);
				//tmp->group = layer;
				best[collection_count] = arr[index];
				*best_count = c + 1 + collection_count;
				best_count_changed = 1;
				current_count = *best_count;
				count = c;
			}
		}
		index++;
		if(index >= arr_count)
			index = 0;
	}
	if(best_count_changed)
	{
		//parent->group = layer;
		best[collection_count - 1] = arr[parent];
	}
	return ++count;
}*/

/*void load_best_sorted_list(int *arr, int arr_count)
{
	int i = -1;
	int best_count = 0;
	int layer = 0;
	int best[arr_count];
	//int smallest = arr[0];
	while(++i < arr_count)
	{
		if(!array_contains_num(best, arr_count, arr[i], 0))
		{
			load_best(arr, arr_count, i, i, best, 1, &best_count, ++layer);
		}
	}

	i = -1;
	while(++i < best_count)
	{
		printf("%d\n", best[i]);
	}
}*/

/*void set_nums_groups()
{
	i = bigest_count_at;
	while (1)
	{
		int index = table[0][i] - 1;
		table[2][index] = arr[i];
		if(i <= 1)
			break;
		i = table[1][i];
	}
}*/

int *init_array(int length, int init_number)
{
	int *arr;
	arr = malloc(sizeof(int) * length);
	int i = 0;
	while(i < length)
		arr[i++] = init_number;
	return arr;
}

int **make_wizard(int length)
{
	int **table;
	table = malloc(sizeof(int *) * 2);
	table[0] = init_array(length, 1);
	table[1] = init_array(length, -1);
	//table[2] = init_array(length, 0);
	return table;
}


/*void load_best_sorted_list(t_stack *stack, int *arr, int length)
{
	int i;
	int **table;
	int bigest_count_at;
	
	i = -1;
	bigest_count_at = 0;
	table = make_wizard(length);
	
	while (++i < length)
	{
		int j = -1;
		while (++j < i)
		{
			if (arr[j] < arr[i] && table[0][j] + 1 > table[0][i])
			{
				table[0][i]++;
				table[1][i] = j;
				if (table[0][i] > table[0][bigest_count_at])
					bigest_count_at = i;
			}
		}
	}
	set_nums_groups(stack, table, bigest_count_at);

	i = -1;
	while(++i < length)
	{
		printf("%d %d %d\n", table[0][i], table[1][i], table[2][i]);
	}
}*/

void reset_stack_sort_helper_values(t_stack *stack)
{
	t_num *tmp;
	tmp = stack->top;
	while(tmp){
		if(tmp->group == 0)
		{
			tmp->sort_count = 1;
			tmp->previous_sort = NULL;
		}
		tmp = tmp->next;
		if(tmp == stack->top)
			break ;
	}
}

void load_swapped_numbers(t_stack *stack, int group)
{
	t_num *previous_sorted_num = stack->sorted_head;
	while(previous_sorted_num)
	{
		t_num *next_sorted_num =  previous_sorted_num->next;
		while(!(next_sorted_num->group == group && next_sorted_num->need_swap == 0))
			next_sorted_num = next_sorted_num->next;
		t_num *tmp = next_sorted_num->next;
		t_num *prev = previous_sorted_num;
		while(tmp->group != group)
		{
			if(tmp->group == 0)
			{
				if(tmp->number > prev->number && (next_sorted_num == stack->sorted_head || tmp->number < next_sorted_num->number))
				{
					tmp->group = group;
					tmp->need_swap = 1;
					//prev = tmp;
				}
			}
			tmp = tmp->next;
		}
		previous_sorted_num = next_sorted_num;
		if(previous_sorted_num == stack->sorted_head)
			break ;
	}
}

/*void load_swapped_numbers(t_stack *stack)
{
	t_num *previous_sorted_num = stack->sorted_head;
	while(previous_sorted_num)
	{
		t_num *next_sorted_num =  previous_sorted_num->next;
		while(next_sorted_num->group != 1)
			next_sorted_num = next_sorted_num->next;
		if(next_sorted_num == stack->sorted_head)
			break ;
		t_num *tmp =  previous_sorted_num->previous;
		while(tmp->group != 1)
		{
			if(tmp->number > previous_sorted_num->number && tmp->number < next_sorted_num->number)
			{
				tmp->group = 1;
				tmp->need_swap = 1;
				break ;
			}
			tmp = tmp->previous;
		}
		previous_sorted_num = next_sorted_num;
	}
}*/

t_num *get_smallest(t_stack *stack)
{
	t_num *tmp = stack->top;
	t_num *smallest = NULL;
	while(tmp)
	{
		if(tmp->group == 0)
		{
			if(!smallest || smallest->number > tmp->number)
				smallest = tmp;
		}
		tmp = tmp->next;
		if(tmp == stack->top)
			break ;
	}
	return smallest;
}

void load_best_sorted_list_reverse(t_stack *stack, t_num *head, t_num *end, int group)
{
	int i;
	t_num *bigest_count_at;
	
	i = -1;
	t_num *tmp = head;
	bigest_count_at = NULL;
	
	reset_stack_sort_helper_values(stack);
	while (tmp != end)
	{
		if(tmp->group == 0)
		{
			t_num *tmp2 = head;
			while (tmp2 != tmp)
			{
				if(tmp2->group == 0)
				{
					if (tmp2->number < tmp->number && tmp2->sort_count + 1 > tmp->sort_count)
					{
						tmp->sort_count++;
						tmp->previous_sort = tmp2;
						if (bigest_count_at == NULL || tmp->sort_count > bigest_count_at->sort_count)
							bigest_count_at = tmp2;
					}
				}
				tmp2 = tmp2->previous;
			}
		}
		tmp = tmp->previous;
	}
	while(bigest_count_at){
		bigest_count_at->group = group;
		if(bigest_count_at->previous_sort == NULL)
			break;
		bigest_count_at = bigest_count_at->previous_sort;
	}
}

int load_best_sorted_list(t_stack *stack, int group)
{
	int i;
	t_num *bigest_count_at;
	
	i = -1;
	t_num *head = get_smallest(stack);
	t_num *tmp = head->next;
	bigest_count_at = NULL;
	
	reset_stack_sort_helper_values(stack);
	int all_groups_loaded = 1;
	while (tmp != head)
	{
		if(tmp->group == 0)
		{
			t_num *tmp2 = head;
			while (tmp2 != tmp)
			{
				if(tmp2->group == 0)
				{
					if (tmp2->number < tmp->number && tmp2->sort_count + 1 > tmp->sort_count)
					{
						tmp->sort_count++;
						tmp->previous_sort = tmp2;
						if (bigest_count_at == NULL || tmp->sort_count > bigest_count_at->sort_count)
							bigest_count_at = tmp;
						all_groups_loaded = 0;
					}
				}
				tmp2 = tmp2->next;
			}
		}
		tmp = tmp->next;
	}
	tmp = bigest_count_at;
	while(tmp){
		tmp->group = group;
		if(tmp->previous_sort == NULL)
			break;
		tmp = tmp->previous_sort;
	}
	stack->sorted_head = tmp;
	/*if(!all_groups_loaded && group > 1 && head != bigest_count_at->next)
		load_best_sorted_list_reverse(stack, tmp->previous, bigest_count_at, group);*/
	/*if(group == 1)
		load_swapped_numbers(stack, group);*/
	return all_groups_loaded;
}

