#include "push_swap.h"

static int stack_size(t_list *stack)
{
	int count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int main (int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int	size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	error_cases(&a, argc, argv);
	size = stack_size(a);	
	if (size == 2)
		num_2(&a);
	else if (size == 3)
		num_3(&a);
	else if (size == 4 || size == 5)
		num_4_5(&a, &b, size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
