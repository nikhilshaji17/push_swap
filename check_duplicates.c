/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:38:07 by nkunnath          #+#    #+#             */
/*   Updated: 2024/09/26 12:38:08 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_list *stack_a)
{
	t_list	*slow;
	t_list	*fast;

	slow = stack_a;
	while (slow)
	{
		fast = slow->next;
		while (fast)
		{
			if (slow->content == fast->content)
			{
				return (0);
			}
			fast = fast->next;
		}
		slow = slow->next;
	}
	return (1);
}
