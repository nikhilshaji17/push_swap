#include "push_swap.h"

int check_duplicates(t_list *stack_a)
{
	t_list *slow;
	t_list *fast;

	slow = stack_a;
	while(slow)
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