/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:39:04 by jaigonza          #+#    #+#             */
/*   Updated: 2025/06/28 14:56:22 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	move_bit(int sig)
{
	g_server.current_char <<= 1;
	if (sig == SIGUSR2)
		g_server.current_char |= 1;
	g_server.bit_count++;
}

void	save_message(int sig)
{
	char	*new_buf;

	move_bit(sig);
	if (g_server.bit_count == 8)
	{
		new_buf = append_char(g_server.message, &g_server.msg_size,
				(char)g_server.current_char);
		if (!new_buf)
		{
			ft_printf("Memory allocation failed\n");
			free(g_server.message);
			exit(EXIT_FAILURE);
		}
		g_server.message = new_buf;
		g_server.current_char = 0;
		g_server.bit_count = 0;
		if (g_server.message[g_server.msg_size - 1] == '\0')
		{
			write(1, g_server.message, g_server.msg_size - 1);
			write(1, "\n", 1);
			kill(g_server.c_pid, SIGUSR1);
			free(g_server.message);
			ft_bzero(&g_server, sizeof(t_server));
		}
	}
}
