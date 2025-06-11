/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:24:03 by mwilline          #+#    #+#             */
/*   Updated: 2025/05/27 18:36:57 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	start_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 1;
	if (argc == 2)
	{
		args = ft_split(argv[i], ' ');
		i = 0;
	}
	else
		args = argv;
	while (args[i])
	{
		new = ft_newlst(ft_atoi(args[i]));
		put_lstback(new, stack);
		i++;
	}
	ft_index(stack);
	if (argc == 2)
		free(args);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	start_stack(stack_a, argc, argv);
	if (is_sort(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	radix(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
