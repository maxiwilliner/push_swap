/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:24:20 by mwilline          #+#    #+#             */
/*   Updated: 2025/05/28 20:58:20 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rep(int nbr, char **args, int i)
{
	int	j;

	j = 1;
	while (j < i)
	{
		if (ft_atoi(args[j]) == nbr)
			return (1);
		j++;
	}
	return (0);
}

int	check_digit(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	if (!num[i])
		return (0);
	while (num[i])
	{
		if (num[i] >= '0' && num[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

static void	validate_arg(char **args, int i)
{
	long	temp;

	if (!check_digit(args[i]))
		ft_error("Error");
	temp = ft_atoi(args[i]);
	if (temp < -2147483648 || temp > 2147483647)
		ft_error("Error");
	if (ft_rep(temp, args, i))
		ft_error("Error");
}

static char	**get_args(int argc, char **argv, int *i)
{
	char	**args;

	*i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
			ft_error("Error");
	}
	else
	{
		args = argv;
		*i = 1;
	}
	return (args);
}

void	check_args(int argc, char **argv)
{
	char	**args;
	int		i;

	args = get_args(argc, argv, &i);
	while (args[i])
	{
		validate_arg(args, i);
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
