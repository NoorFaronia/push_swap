/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaronia <nfaronia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:55:01 by nfaronia          #+#    #+#             */
/*   Updated: 2026/01/07 17:05:47 by nfaronia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bit(int max_num)
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

void	bubble_sort(int *tab, int size)
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

void	sort_indix(int *arr, int size, t_list *node)
{
	int	i;

	while (node)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == node->value)
			{
				node->index = i;
				break ;
			}
			i++;
		}
		node = node->next;
	}
}

void	index_numbers(t_list **stack, int size)
{
	t_list	*node;
	int		*arr;
	int		i;

	if (!stack || !*stack)
		return ;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	node = *stack;
	i = 0;
	while (node)
	{
		arr[i++] = node->value;
		node = node->next;
	}
	bubble_sort(arr, size);
	node = *stack;
	sort_indix(arr, size, node);
	free(arr);
}

void	radix_sort(t_list **a, t_list **b, int size)
{
	int	max_bits;
	int	i;
	int	j;

	if (!a || !*a)
		return ;
	index_numbers(a, size);
	max_bits = max_bit(size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
