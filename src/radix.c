/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:24:16 by mwilline          #+#    #+#             */
/*   Updated: 2025/05/27 18:31:53 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_list **stack_a, t_list **stack_b)
{
	if (list_size(*stack_a) <= 5)
		brute_force(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	get_bit(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (max < head->index)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	max_bit;
	int	current;

	i = 0;
	max_bit = get_bit(stack_a);
	while (i < max_bit)
	{
		size = list_size(*stack_a);
		j = 0;
		while (j < size)
		{
			current = (*stack_a)->index;
			if ((current >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (list_size(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
