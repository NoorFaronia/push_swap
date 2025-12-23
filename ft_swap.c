#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*rest;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	rest = second->next;
	second->next = first;
	first->next = rest;
	*stack = second;
}

void	sa(t_list **a)
{
	swap(a);
	write (1, "sa\n", 3);
}

void	sb(t_list **b)
{
	swap(b);
	write (1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	write (1, "ss\n", 3);
}
