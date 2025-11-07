/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_thing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:10:56 by jaigonza          #+#    #+#             */
/*   Updated: 2025/07/31 13:13:58 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	jump_spaces(char **str)
{
	while (**str == ' ' || **str == '\t' || **str == '\n' || **str == '\r'
		|| **str == '\f' || **str == '\v')
		(*str)++;
}

void	flag_thing(t_stack_node **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	jump_spaces(&av[i]);
	if (error_syntax(av[i]))
		free_errors(a);
	n = ft_atol(av[i]);
	if (n < INT_MIN || n > INT_MAX)
		free_errors(a);
	if (error_duplicate(*a, (int)n))
		free_errors(a);
	append_node(a, (int)n);
}
