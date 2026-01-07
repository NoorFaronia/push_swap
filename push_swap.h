/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaronia <nfaronia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:49:12 by nfaronia          #+#    #+#             */
/*   Updated: 2026/01/07 16:53:45 by nfaronia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int					value;
	int					index;
	struct s_list		*next;
}						t_list;

// utils
size_t	ft_strlen(const char *s);
void	free_split(char **split);
int		is_sorted(t_list *a);

// stack
t_list	*new_node(int value);
void	add_end(t_list **stack, t_list *new);
void	free_stack(t_list **stack);
int		stack_size(t_list *stack);

// parsing
long	error_num(char *str, long *Number);
char	**ft_split(char const *s, char c);
int		error_duplicate(t_list *a, int value);
int		error_cases_and_build(t_list **a, int argc, char **argv);

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
void	radix_sort(t_list **a, t_list **b, int size);
void	bubble_sort(int *tab, int size);
int		max_bits(int max_num);
void	index_numbers(t_list **stack, int size);
void	sort_indix(int *arr, int size, t_list *node);

#endif
