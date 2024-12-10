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

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i += 1;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		exit(0);
	if (check_input(argc, argv) == 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(STDERR_FILENO);
	}
	stack_a = node_creation(argc, argv);
	if (stack_a == NULL || check_duplicates(stack_a) == 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_lstclear(&stack_a);
		exit(STDERR_FILENO);
	}
	sort_stacks(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	exit(0);
}
