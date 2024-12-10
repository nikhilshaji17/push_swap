/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:24:22 by nkunnath          #+#    #+#             */
/*   Updated: 2024/11/30 17:24:23 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_min(t_list **stack_a)
{
	t_list	*min_node;
	t_list	*ptr;

	min_node = *stack_a;
	ptr = *stack_a;
	while (min_node->flag != 0)
		min_node = min_node->next;
	while (ptr)
	{
		if (ptr->flag == 0)
		{
			if ((ptr->content < min_node->content))
				min_node = ptr;
		}
		ptr = ptr->next;
	}
	return (min_node);
}

static void	set_index(t_list **stack_a)
{
	int		index;
	int		i;
	int		size;
	t_list	*min_node;

	index = 0;
	i = 0;
	size = ft_lstsize(*stack_a);
	while (i < size)
	{
		min_node = find_min(stack_a);
		min_node->index = index;
		min_node->flag = 1;
		index += 1;
		i += 1;
	}
}

static int	find_largest(t_list **stack_a)
{
	t_list	*ptr;
	int		max;

	max = 0;
	ptr = *stack_a;
	while (ptr)
	{
		if (ptr->index > max)
			max = ptr->index;
		ptr = ptr->next;
	}
	return (max);
}

static int	find_max_bits(t_list **stack_a)
{
	int	largest;
	int	count;

	largest = find_largest(stack_a);
	count = 0;
	while (largest > 0)
	{
		count += 1;
		largest /= 2;
	}
	return (count);
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int		max_bits;
	int		i;
	int		count;

	max_bits = 0;
	set_index(stack_a);
	max_bits = find_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		count = ft_lstsize(*stack_a);
		while (count)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
			count -= 1;
		}
		while (*stack_b)
			push_a(stack_a, stack_b);
		i++;
	}
}
