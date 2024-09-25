#include "push_swap.h"

void swap(t_list *stack)
{
	t_list *node;
	int		temp;

	node = stack;
	if (node == NULL || node->next == NULL)
		return ;
	while (node->next->next != NULL)
		node = node->next;
	temp = node->content;
	node->content = node->next->content;
	node->next->content = temp;
}

void swap_both(t_list *stack_one, t_list *stack_two)
{
	swap(stack_one);
	swap(stack_two);
}

void rotate(t_list *stack)
{
    t_list *current;
    t_list *prev;
    int last_value;
}

void rotate_both(t_list *stack_one, t_list *stack_two)
{
	rotate(stack_one);
	rotate(stack_two);	
}

// void push(t_list *stack_one, t_list *stack_two)
// {

// }


// void rev_rot()
// {

// }

// void rev_rot_both()
// {

// }