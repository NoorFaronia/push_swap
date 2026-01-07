/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_cases_and_build.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaronia <nfaronia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:18:58 by nfaronia          #+#    #+#             */
/*   Updated: 2026/01/07 14:39:57 by nfaronia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	error_num(char *str, long *Number)
{
	long	num;
	int		s;

	num = 0;
	s = 1;
	if (!*str)
		return (0);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		num = num * 10 + (*str - '0');
		if ((num * s) > 2147483647 || (num * s) < -2147483648)
			return (0);
		str++;
	}
	*Number = num * s;
	return (1);
}

int	error_duplicate(t_list *a, int value)
{
	while (a)
	{
		if (a->value == value)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	if_error(t_list **a, char **split, long *n, int j)
{
	if (!error_num(split[j], n) || error_duplicate(*a, (int)(*n)))
	{
		free_split(split);
		return (0);
	}
	return (1);
}

int	error_cases_and_build(t_list **a, int argc, char **argv)
{
	int		i;
	char	**split;
	int		j;
	long	num;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			if (!if_error(a, split, &num, j))
				return (0);
			add_end(a, new_node((int)num));
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}
