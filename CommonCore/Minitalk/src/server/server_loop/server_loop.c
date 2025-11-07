/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:49:36 by jaigonza          #+#    #+#             */
/*   Updated: 2025/07/05 16:23:45 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_state(void)
{
	size_t	z;

	z = 0;
	while (g_server.clean == 0)
	{
		z = 0;
		if (g_server.clean == 1)
			break ;
	}
	while (g_server.clean == 1)
	{
		z = 1;
		if (z > 100000)
		{
			clean();
		}
		if (g_server.clean == 0)
			break ;
		z++;
	}
	g_server.clean = 1;
	return (0);
}

void	server_loop(void)
{
	size_t	i;

	i = 0;
	while (1)
	{
		usleep(i * 327);
		if (i > 500000 && i < 1000000)
			usleep(100 * i);
		i++;
		check_state();
	}
}
