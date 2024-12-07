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

void	swap_a(t_list *stack_a)
{
	t_list	*node;
	int		temp_content;
	int		temp_index;

	node = stack_a;
	if (!node || !node->next)
		return ;
	temp_content = node->content;
	temp_index = node->index;
	node->content = node->next->content;
	node->index = node->next->index;
	node->next->content = temp_content;
	node->next->index = temp_index;
	ft_printf("sa\n");
}

void	swap_b(t_list *stack_b)
{
	t_list	*node;
	int		temp_content;
	int		temp_index;

	node = stack_b;
	if (!node || !node->next)
		return ;
	temp_content = node->content;
	temp_index = node->index;
	node->content = node->next->content;
	node->index = node->next->index;
	node->next->content = temp_content;
	node->next->index = temp_index;
	ft_printf("sb\n");
}

void	swap_both(t_list *stack_a, t_list *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
