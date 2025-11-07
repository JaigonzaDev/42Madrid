/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:36:12 by jaigonza          #+#    #+#             */
/*   Updated: 2025/07/31 11:57:40 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_number(const char *str)
{
	int		i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(char *arg)
{
	char	**sp;
	int		count;
	int		i;

	i = 0;
	count = 0;
	sp = split(arg, ' ');
	if (!sp)
		return (0);
	while (sp[i])
	{
		if (ft_number(sp[i]))
			count++;
		i++;
	}
	i = 0;
	while (sp[i])
		free(sp[i++]);
	free(sp);
	if (count > 1)
		return (1);
	else
		return (0);
}
