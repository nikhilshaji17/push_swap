#include "push_swap.h"

void	tiny_sort(t_list **stack_a)
{
	t_list	*highest_node;

	if (((*stack_a)->content) > ((*stack_a)->next->content))
	{
		if (((*stack_a)->content) > ((*stack_a)->next->next->content))
			highest_node = *stack_a;
		else
			highest_node = (*stack_a)->next->next;
	}
	else
	{
		if ((*stack_a)->next->content > (*stack_a)->next->next->content)
			highest_node = (*stack_a)->next;
		else
			highest_node = (*stack_a)->next->next;
	}
	if ((*stack_a)->content == highest_node->content)
		rotate_a(*stack_a);
	else if ((*stack_a)->next->content == highest_node->content)
		rev_rotate_a(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap_a(*stack_a);
}
void	sort_stacks(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	if (stack_size == 1)
		return ;
	else if (stack_size == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_a(*stack_a);
	}
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else
		big_sort(stack_a, stack_b);
}
