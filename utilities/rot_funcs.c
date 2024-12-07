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

#include "../push_swap.h"

void	rotate_a(t_list *stack_a)
{
	t_list		*slow;
	t_list		*fast;
	int			temp;
	long long	index;

	if (!stack_a || !stack_a->next)
		return ;
	slow = stack_a;
	fast = stack_a->next;
	temp = stack_a->content;
	index = stack_a->index;
	while (fast)
	{
		slow->content = fast->content;
		slow->index = fast->index;
		slow = fast;
		fast = fast->next;
	}
	slow->content = temp;
	slow->index = index;
	ft_printf("ra\n");
}

void	rotate_b(t_list *stack_b)
{
	t_list		*slow;
	t_list		*fast;
	int			temp;
	long long	index;

	if (!stack_b || !stack_b->next)
		return ;
	slow = stack_b;
	fast = stack_b->next;
	temp = stack_b->content;
	index = stack_b->index;
	while (fast)
	{
		slow->content = fast->content;
		slow->index = fast->index;
		slow = fast;
		fast = fast->next;
	}
	slow->content = temp;
	slow->index = index;
	ft_printf("rb\n");
}

void	rotate_both(t_list *stack_a, t_list *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}
