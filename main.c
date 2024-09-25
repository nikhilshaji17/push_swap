#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *temp;

	stack_a = node_creation(argc, argv);
	if (stack_a == NULL) // This means that some malloc failed, or we have numbers that cross boundaries
	{
		printf("Node creation failed\n");
		return (0);
	}	
	if (check_duplicates(stack_a) == 0) // This means that we have dupes in our input
	{
		printf("Duplicates found\n");
		ft_lstclear(&stack_a);
		return (0);
	}
	// temp = stack_a;
	// while(temp)
	// {
	// 	printf("%d\n", temp->content);
	// 	temp = temp->next;
	// }
	// swap(stack_a);
	// printf("Swap function called\n");
	// temp = stack_a;
	// while(temp)
	// {
	// 	printf("%d\n", temp->content);
	// 	temp = temp->next;
	// }
	rotate(stack_a);
	printf("Rotate function called\n");
}