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

/*static int	get_max_bits(int max_num)
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

static int	get_max_value(t_list *stack)
{
	int		max;
	t_list	*temp;

	if (!stack)
		return (0);
	temp = stack;
	max = temp->value;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}


static void	normalize_numbers(t_list **stack)
{
	t_list	*current;
	int		min_value;
	int		offset;

	if (!stack || !*stack)
		return ;
	current = *stack;
	min_value = current->value;
	while (current)
	{
		if (current->value < min_value)
			min_value = current->value;
		current = current->next;
	}
	if (min_value < 0)
	{
		offset = -min_value;
		current = *stack;
		while (current)
		{
			current->value += offset;
			current = current->next;
		}
	}
}

void	radix_sort(t_list **a, t_list **b)
{
	int	max_value;
	int	max_bits;
	int	size;
	int	i;
	int	j;

	if (!a || !*a || is_sorted(*a))
		return ;
	normalize_numbers(a);
	max_value = get_max_value(*a);
	max_bits = get_max_bits(max_value);
	i = -1;
	while (++i < max_bits)
	{
		size = stack_size(*a);
		j = -1;
		while (++j < size)
		{
			if ((((*a)->value >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		while (*b)
			pa(a, b);
	}
}

/////////////////////////////////////
#include "push_swap.h"


void	radix_sort(t_list **a, t_list **b)
{
	int	max_val;
	int	max_bits;
	int	size;
	int	i;
	int	j;
	int	ra_count;

	if (!a || !*a || is_sorted(*a))
		return ;
	max_val = get_max_value(*a);
	max_bits = get_max_bits(max_val);
	i = 0;
	while (i < max_bits)
	{
		size = stack_size(*a);
		ra_count = 0;
		j = 0;
		while (j < size)
		{
			if ((((*a)->value >> i) & 1) == 1)
			{
				ra(a);
				ra_count++;
			}
			else
				pb(a, b);
			j++;
		}
		while (ra_count-- > 0)
			rra(a);
		while (*b)
			pa(a, b);
		i++;
	}
}*/
