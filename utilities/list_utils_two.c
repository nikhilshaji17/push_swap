/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:41:55 by nkunnath          #+#    #+#             */
/*   Updated: 2024/12/05 16:41:57 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		count;

	count = 0;
	node = lst;
	while (node != NULL)
	{
		count += 1;
		node = node->next;
	}
	return (count);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL)
	{
		lst = &new;
		return ;
	}
	else if (new == NULL)
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	node = lst;
	if (lst == NULL)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}
