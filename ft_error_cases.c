/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaronia <nfaronia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:18:58 by nfaronia          #+#    #+#             */
/*   Updated: 2025/12/24 13:28:18 by nfaronia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	error_duplicate(t_list *a, int value)
{
	while (a)
	{
		if (a->value == value)
			error();
		a = a->next;
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	error_cases(t_list **a, int argc, char **argv)
{
	int		i;
	char	**split;
	int		j;
	long	n;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			error();
		j = 0;
		while (split[j])
		{
			if (!error_num(split[j]))
				error();
			n = ft_atol(split[j]);
			error_duplicate(*a, (int)n);
			add_back(a, new_node((int)n));
			j++;
		}
		free_split(split);
		i++;
	}
}
