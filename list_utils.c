#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*node;
	t_list	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	node = *lst;
	while (node != NULL)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
	*lst = NULL;
	return ;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *lst;
	if (new == NULL || lst == NULL)
		return ;
	else if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (node->next != NULL)
		node = node->next;
	node->next = new;
	return ;
}