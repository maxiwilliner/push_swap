/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:23:43 by mwilline          #+#    #+#             */
/*   Updated: 2025/05/27 20:29:21 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

// utils
void	ft_error(char *msg);
int		is_sort(t_list **stack);
void	free_stack(t_list **stack);
int		get_min_arg(t_list **stack);
int		get_distance(t_list **stack);
void	ft_free(char **args);
// cheacks
int		ft_rep(int nbr, char **args, int i);
int		cheak_digit(char *num);
void	check_args(int argc, char **argv);

// index
t_list	*get_min(t_list **stack);
void	ft_index(t_list **stack);
// list
t_list	*ft_newlst(int value);
t_list	*find_last(t_list *stack);
void	put_lstback(t_list *new, t_list **stack);
int		list_size(t_list *head);

// brute
void	brute_force(t_list **stack_a, t_list **stack_b);
void	two_args(t_list **stack_a);
void	three_args(t_list **stack_a);
void	four_args(t_list **stack_a, t_list **stack_b);
void	five_args(t_list **stack_a, t_list **stack_b);
// ops
void	sa(t_list **stack);
void	sb(t_list *stack);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rra(t_list **stack);
void	rrb(t_list **stack);
// radix
void	radix(t_list **stack_a, t_list **stack_b);
int		get_bit(t_list **stack);
void	radix_sort(t_list **stack_a, t_list **stack_b);

#endif
