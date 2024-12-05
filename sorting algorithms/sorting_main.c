/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:24:31 by nkunnath          #+#    #+#             */
/*   Updated: 2024/11/30 17:24:32 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	three_sort(t_list **stack_a)
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

void	four_sort(t_list **stack_a, t_list **stack_b)
{
	push_b(stack_a, stack_b);
	three_sort(stack_a);
	push_a(stack_a, stack_b);
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		if ((*stack_a)->content < (*stack_a)->next->next->content)
			swap_a(*stack_a);
		else if (((*stack_a)->content) < (*stack_a)->next->next->next->content)
		{
			swap_a(*stack_a);
			rotate_a(*stack_a);
			swap_a(*stack_a);
			rev_rotate_a(stack_a);
		}
		else
			rotate_a(*stack_a);
	}
}

void	five_sort(t_list **a, t_list **b)
{
	push_b(a, b);
	four_sort(a, b);
	push_a(a, b);
	if ((*a)->content > (*a)->next->content)
	{
		if ((*a)->content < (*a)->next->next->content)
			swap_a(*a);
		else if (((*a)->content) < (*a)->next->next->next->content)
		{
			swap_a(*a);
			rotate_a(*a);
			swap_a(*a);
			rev_rotate_a(a);
		}
		else if (((*a)->content) < (*a)->next->next->next->next->content)
		{
			rev_rotate_a(a);
			swap_a(*a);
			rotate_a(*a);
			rotate_a(*a);
		}
		else
			rotate_a(*a);
	}
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
		three_sort(stack_a);
	else if (stack_size == 4)
		four_sort(stack_a, stack_b);
	else if (stack_size == 5)
		five_sort(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
}
