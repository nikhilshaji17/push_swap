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

void	rotate_a(t_list **stack_a)
{
	t_list		*first;
	t_list		*second;
	t_list		*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*stack_a = second;
	ft_printf("ra\n");
}

void	rotate_b(t_list **stack_b)
{
	t_list		*first;
	t_list		*second;
	t_list		*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*stack_b = second;
	ft_printf("rb\n");
}

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}
