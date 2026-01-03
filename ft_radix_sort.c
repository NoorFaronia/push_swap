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

int	max_num(t_list *stack)
{
	int		m;
	t_list	*h;

	if (!stack)
		return (0);
	m = stack->value;
	h = stack->next;
	while (h)
	{
		if (h->value > m)
			m = h->value;
		h = h->next;
	}
	return (m);
}

int get_max_bits(int max)
{
    int bits = 0;
    while ((max >> bits) != 0)
        bits++;
    return bits;
}

void map_to_indices(t_list *stack)
{
    t_list *i, *j;
    int count;

    for (i = stack; i; i = i->next)
    {
        count = 0;
        for (j = stack; j; j = j->next)
        {
            if (i->value > j->value)
                count++;
        }
        i->value = count;
    }
}

void radix_sort(t_list **a, t_list **b)
{
    int max;
    int max_bits;
    int i, j;
    int size;

    if (!a || !*a)
        return;

    map_to_indices(*a);          // Step 1: normalize numbers
    max = max_num(*a);
    max_bits = get_max_bits(max);
    size = stack_size(*a);

    for (i = 0; i < max_bits; i++)
    {
        j = 0;
        while (j < size)
        {
            if (((*a)->value >> i) & 1)
                ra(a);  // rotate
            else
                pb(a, b); // push to b
            j++;
        }
        while (*b)
            pa(b, a); // move back to a
    }
}
