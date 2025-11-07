/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:43:25 by jaigonza          #+#    #+#             */
/*   Updated: 2025/07/22 12:43:25 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int		i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	check_spaces(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i + 1] != ' ')
			break ;
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	handle_input(int ac, char **av, t_stack_node **a, char ***split_args)
{
	int		i;

	i = 1;
	if (ac > 1)
	{
		while (ac > i)
		{
			if (check_args(av[i]) == 0)
				init_stack_a(a, &av[i], 1);
			else
			{
				*split_args = split(av[i], ' ');
				if (!*split_args)
				{
					ft_printf("Error\n");
					return (1);
				}
				init_stack_a(a, *split_args, 0);
			}
			i++;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_args;

	a = NULL;
	b = NULL;
	split_args = NULL;
	if (handle_input(ac, av, &a, &split_args))
		return (1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	if (split_args)
		free_split(split_args);
	return (0);
}
