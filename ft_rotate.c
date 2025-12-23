#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list *cut;
	t_list *tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	cut = *stack;
	*stack = cut->next;
	cut->next = NULL;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	tail->next = cut;
}

void	ra(t_list **a)
{
	rotate(a);
	write (1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rotate(b);
	write (1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write (1, "rr\n", 3);
}
