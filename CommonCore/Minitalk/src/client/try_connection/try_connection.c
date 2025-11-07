/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_connection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:29:13 by jaigonza          #+#    #+#             */
/*   Updated: 2025/06/28 14:45:43 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	try_config(void)
{
	struct sigaction	confirm;
	sigset_t			sigset;

	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	confirm.sa_flags = SA_SIGINFO;
	confirm.sa_sigaction = try_connection_handler;
	sigaction(SIGUSR1, &confirm, NULL);
	sigaction(SIGUSR2, &confirm, NULL);
}

void	try_connection(void)
{
	int	timeout;

	timeout = 0;
	try_config();
	while (g_client.ok != 1)
	{
		ft_printf("Trying to connect to server....\n");
		kill(g_client.pid, SIGUSR1);
		if (g_client.ok != 1)
		{
			ft_printf("Waiting for response...\n");
			sleep(2);
			timeout++;
		}
		if (timeout == 5)
		{
			ft_printf("Can't connect to the server\n");
			exit(1);
		}
	}
}
