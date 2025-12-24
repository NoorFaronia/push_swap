/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaronia <nfaronia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:48:00 by nfaronia          #+#    #+#             */
/*   Updated: 2025/12/24 14:09:47 by nfaronia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_size(t_list *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

static int	is_sorted(t_list *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	error_cases(&a, argc, argv);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
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
