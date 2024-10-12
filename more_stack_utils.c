/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:33:16 by nkunnath          #+#    #+#             */
/*   Updated: 2024/09/26 12:33:18 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_list **stack_a)
{
	t_list	*second_last;
	t_list	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	second_last = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	while (second_last->next->next)
		second_last = second_last->next;
	last->next = *stack_a;
	second_last->next = NULL;
	*stack_a = last;
	printf("rra\n");
}

void	rev_rotate_b(t_list **stack_b)
{
	t_list	*second_last;
	t_list	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	second_last = *stack_b;
	last = *stack_b;
	while (last->next)
		last = last->next;
	while (second_last->next->next)
		second_last = second_last->next;
	last->next = *stack_b;
	second_last->next = NULL;
	*stack_b = last;
	printf("rrb\n");
}

void	rev_rotate_both(t_list **stack_a, t_list **stack_b)
{
	rev_rotate_a(stack_a);
	rev_rotate_b(stack_b);
}

void	rotate_a(t_list *stack_a)
{
	t_list	*slow;
	t_list	*fast;
	int		temp;

	if (!stack_a || !stack_a->next)
		return ;
	slow = stack_a;
	fast = stack_a->next;
	temp = stack_a->content;
	while (fast)
	{
		slow->content = fast->content;
		slow = fast;
		fast = fast->next;
	}
	slow->content = temp;
	printf("ra\n");
}

void	rotate_b(t_list *stack_b)
{
	t_list	*slow;
	t_list	*fast;
	int		temp;

	if (!stack_b || !stack_b->next)
		return ;
	slow = stack_b;
	fast = stack_b->next;
	temp = stack_b->content;
	while (fast)
	{
		slow->content = fast->content;
		slow = fast;
		fast = fast->next;
	}
	slow->content = temp;
	printf("rb\n");
}

void	rotate_both(t_list *stack_a, t_list *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}
