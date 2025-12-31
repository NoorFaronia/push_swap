/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaronia <nfaronia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:47:42 by nfaronia          #+#    #+#             */
/*   Updated: 2025/12/31 14:09:47 by nfaronia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_value(t_list *a)
{
	int	min;

	if (!a)
		return (0);
	min = a->value;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

static int	find_min_index(t_list *a)
{
	int	min;
	int	i;

	min = get_min_value(a);
	i = 0;
	while (a)
	{
		if (a->value == min)
			return (i);
		i++;
		a = a->next;
	}
	return (0);
}

static void	move_min_to_top(t_list **a)
{
	int	min_index;
	int	size;

	size = stack_size(*a);
	if (size < 2)
		return ;
	min_index = find_min_index(*a);
	if (min_index <= size / 2)
	{
		while (min_index-- > 0)
			ra(a);
	}
	else
	{
		min_index = size - min_index;
		while (min_index-- > 0)
			rra(a);
	}
}

void	radix_sort(t_list **a, t_list **b)
{
	while (*a)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
}
