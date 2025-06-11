/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:24:11 by mwilline          #+#    #+#             */
/*   Updated: 2025/05/27 18:40:47 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	ft_putendl_fd("sa", 1);
}

void	sb(t_list *stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !stack->next)
		return ;
	first = stack;
	second = stack->next;
	first->next = second->next;
	second->next = first;
	stack = second;
	ft_putendl_fd("sb", 1);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_b;

	if (!*stack_b)
		return ;
	first_b = *stack_b;
	*stack_b = first_b->next;
	first_b->next = *stack_a;
	*stack_a = first_b;
	ft_putendl_fd("pa", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;

	if (!stack_a)
		return ;
	first_a = *stack_a;
	*stack_a = first_a->next;
	first_a->next = *stack_b;
	*stack_b = first_a;
	ft_putendl_fd("pb", 1);
}

void	ra(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	ft_putendl_fd("ra", 1);
}
