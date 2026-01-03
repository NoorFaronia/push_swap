/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaronia <nfaronia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:55:01 by nfaronia          #+#    #+#             */
/*   Updated: 2026/01/03 15:23:52 by nfaronia         ###   ########.fr       */
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

void radix_sort(t_list **a, t_list **b)
{
    int max;
    int max_bits;
    int i, j;
    int size;

    if (!a || !*a)
        return;

    max = max_num(*a);
    max_bits = get_max_bits(max);

    size = stack_size(*a);

    for (i = 0; i < max_bits; i++)
    {
        j = 0;
        while (j < size)
        {
            if (((*a)->value >> i) & 1)
                ra(a);
            else
                pb(a, b);
            j++;
        }
        while (*b)
            pa(b, a);
    }
}
