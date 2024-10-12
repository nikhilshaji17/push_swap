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

void	swap_a(t_list *stack_a)
{
	t_list	*node;
	int		temp;

	node = stack_a;
	if (!node || !node->next)
		return ;
	temp = node->content;
	node->content = node->next->content;
	node->next->content = temp;
	printf("sa\n");
}

void	swap_b(t_list *stack_b)
{
	t_list	*node;
	int		temp;

	node = stack_b;
	if (!node || !node->next)
		return ;
	temp = node->content;
	node->content = node->next->content;
	node->next->content = temp;
	printf("sb\n");
}

void	swap_both(t_list *stack_a, t_list *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_b)
		return ;
	temp = ft_lstlast(*stack_b);
	ft_lstadd_back(stack_a, temp);
	if (*stack_b == temp)
		*stack_b = NULL;
	else
	{
		t_list *current = *stack_b;
        while (current->next != temp) {
            current = current->next;
        }
        current->next = NULL;
	}
	printf("pa\n");
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_a)
		return ;
	temp = ft_lstlast(*stack_a);
	ft_lstadd_back(stack_b, temp);
	if (*stack_a == temp)
		*stack_a = NULL;
	else
	{
		t_list *current = *stack_a;
        while (current->next != temp) {
            current = current->next;
        }
        current->next = NULL;
	}
	printf("pb\n");
}
