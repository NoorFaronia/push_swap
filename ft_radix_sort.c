/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaronia <nfaronia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 15:16:28 by nfaronia          #+#    #+#             */
/*   Updated: 2025/12/31 15:23:56 by nfaronia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

static t_list *min_to_head(t_list *head)
{
    t_list *min;
    t_list *min_prev;
    t_list *curr;
    t_list *prev;

    if (!head || !head->next)
        return head;

    min = head;
    min_prev = NULL;
    curr = head;
    prev = NULL;

    while (curr)
    {
        if (curr->value < min->value)
        {
            min = curr;
            min_prev = prev;
        }
        prev = curr;
        curr = curr->next;
    }

    if (!min_prev)
        return head;

    min_prev->next = min->next;
    min->next = head;
    head = min;

    return head;
}

void radix_sort(t_list **a, t_list **b)
{
    while (*a)
    {
        *a = min_to_head(*a);
        pb(a, b);
    }
    while (*b)
        pa(a, b);
}
