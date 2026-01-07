/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaronia <nfaronia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:31:20 by nfaronia          #+#    #+#             */
/*   Updated: 2026/01/07 14:53:20 by nfaronia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*bigen;
	t_list	*end;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	bigen = *stack;
	*stack = bigen->next;
	bigen->next = NULL;
	end = *stack;
	while (end->next)
		end = end->next;
	end->next = bigen;
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
