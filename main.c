#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list *stack_a;

	printf("Here\n");
	stack_a = node_creation(argc, argv);
	if (stack_a == NULL) // This means that some malloc failed, or we have numbers that cross boundaries
		return (0);
	printf("%d\n", stack_a->content);
	// if (check_duplicates(stack_a) == 0) // This means that we have dupes in our input
	// 	return (0);
}