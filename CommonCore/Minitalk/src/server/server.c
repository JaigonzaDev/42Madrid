/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:24:17 by jaigonza          #+#    #+#             */
/*   Updated: 2025/07/05 16:26:35 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server	g_server;

void	show_pid(void)
{
	pid_t	server_id;

	server_id = getpid();
	ft_printf("server ID -> %u\n", server_id);
}

/*
 *	1. Show the server's PID.
 *	2. Configure the signals handler.
 *	3. Start the server loop.
 */
int	main(void)
{
	clean();
	show_pid();
	server_config();
	server_loop();
	return (0);
}
