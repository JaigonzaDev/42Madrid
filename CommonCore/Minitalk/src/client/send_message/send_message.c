/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:00:05 by jaigonza          #+#    #+#             */
/*   Updated: 2025/06/28 14:50:00 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(pid_t server_pid, int bit)
{
	int	signal;

	if (bit)
		signal = SIGUSR2;
	else
		signal = SIGUSR1;
	if (kill(server_pid, signal) == -1)
	{
		ft_printf("Failed to send signal\n");
		exit(EXIT_FAILURE);
	}
}

void	send_char(pid_t server_pid, char c)
{
	int	i;
	int	bit;

	bit = 0;
	i = 7;
	while (i >= 0)
	{
		g_client.ready = 0;
		bit = (c >> i) & 1;
		send_bit(server_pid, bit);
		while (g_client.ready != 1)
			usleep(1);
		i--;
	}
}

void	send_message(char *message, pid_t server_pid)
{
	size_t	i;
	char	c;

	i = 0;
	while (1)
	{
		c = message[i];
		send_char(server_pid, c);
		if (c == '\0')
			exit(1);
		i++;
	}
}
