#include "push_swap.h"

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