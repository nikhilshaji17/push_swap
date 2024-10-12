/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:35:43 by nkunnath          #+#    #+#             */
/*   Updated: 2024/09/26 12:35:45 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_list *head)
{
	if (!head)
		return ;
	printf("%i, ", head->content);
	print_list(head->next);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1 || check_input(argc, argv) == 0)
	{
		printf("Incorrect Input\n");
		return (0);
	}
	stack_a = node_creation(argc, argv);
	if (stack_a == NULL)
	{
		printf("Node creation failed\n");
		return (0);
	}
	printf("Stack Created\n");
	if (check_duplicates(stack_a) == 0)
	{
		printf("Duplicates found\n");
		ft_lstclear(&stack_a);
		return (0);
	}
	sort_stacks(&stack_a, &stack_b);
	return (0);
}
