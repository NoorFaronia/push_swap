#include "push_swap.h"

void	push(t_list **first_stack, t_list **second_stack)
{
	t_list *node;

	if (!first_stack || !*first_stack)
		return ;
	node = *first_stack;
	*first_stack = node->next;
	node->next = *second_stack;
	*second_stack = node;
}

void	pa(t_list **a, t_list **b)
{
	push(b, a);
	write (1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	push(a, b);
	write (1, "pb\n", 3);
}
