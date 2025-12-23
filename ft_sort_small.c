#include "push_swap.h"

void	num_2(t_list **a)
{
	int	first;
	int	second;

	first = (*a)->value;
	second = (*a)->next->value;
	if (first > second)
		sa(a);
}

void	num_3(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	find_min(t_list **a, t_list **b, int size)
{
	int		i;
	int		min;
	t_list	*tmp;

	if (size == 4)
		i = 1;
	else
		i = 0;
	while (i < 2)
	{
		tmp = *a;
		min = tmp->value;
		while (tmp)
		{
			if (tmp->value < min)
				min = tmp->value;
			tmp = tmp->next;
		}
		if ((*a)->value == min)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

void	num_4_5(t_list **a, t_list **b, int size)
{
	find_min(a, b, size);
	num_3(a);
	while (*b)
		pa(a, b);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
