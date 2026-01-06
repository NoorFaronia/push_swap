/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaronia <nfaronia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:55:01 by nfaronia          #+#    #+#             */
/*   Updated: 2026/01/03 15:56:51 by nfaronia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_num)
{
	int	bits;

	bits = 0;
	while (max_num > 0)
	{
		max_num = max_num >> 1;
		bits++;
	}
	return (bits);
}

static void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	normalize_numbers(t_list **stack)
{
	t_list	*current;
	int		*arr;
	int		i;
	int		size;

	if (!stack || !*stack)
		return ;
	size = stack_size(*stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	current = *stack;
	i = 0;
	while (current)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	ft_sort_int_tab(arr, size);
	current = *stack;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == current->value)
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free(arr);
}

void	radix_sort(t_list **a, t_list **b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

	if (!a || !*a || is_sorted(*a))
		return ;
	normalize_numbers(a);
	max_bits = get_max_bits(stack_size(*a) - 1);
	i = -1;
	while (++i < max_bits)
	{
		size = stack_size(*a);
		j = -1;
		while (++j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		while (*b)
			pa(a, b);
	}
}
