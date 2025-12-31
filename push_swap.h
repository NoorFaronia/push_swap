/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaronia <nfaronia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:49:12 by nfaronia          #+#    #+#             */
/*   Updated: 2025/12/31 11:48:49 by nfaronia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int					value;
	int					index;
	struct s_list		*next;
}						t_list;

// utils
size_t	ft_strlen(const char *s);
int		stack_size(t_list *stack);

// stack
t_list	*new_node(int value);
void	add_back(t_list **stack, t_list *new);
void	free_stack(t_list **stack);

// parsing
long	error_num(char *str, long *out);
char	**ft_split(char const *s, char c);
void	free_split(char **split);
int		error_duplicate(t_list *a, int value);
int		error_cases(t_list **a, int argc, char **argv);

// swap
void	swap(t_list **stack);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

// push
void	push(t_list **first_stack, t_list **second_stack);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

// rotate
void	rotate(t_list **stack);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);

// reverse rotate
void	reverse_rotate(t_list **stack);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

// sort_small
void	num_2(t_list **a);
void	num_3(t_list **a);
void	num_4_5(t_list **a, t_list **b, int size);
void	find_min(t_list **a, t_list **b, int size, int min);

//sort_big
void	radix_sort(t_list **a, t_list **b);

//print
void	print_stack(t_list *a);

#endif
