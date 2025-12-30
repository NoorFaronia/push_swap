#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_list *a)
{
	while (a)
	{
		printf("%d ", a->value);
		a = a->next;
	}
	printf("\n");
}
