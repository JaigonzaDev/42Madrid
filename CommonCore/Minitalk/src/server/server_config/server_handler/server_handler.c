/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:36:35 by jaigonza          #+#    #+#             */
/*   Updated: 2025/07/05 16:34:04 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	g_server.clean = 0;
	g_server.c_pid = info->si_pid;
	if (g_server.act_pid == 0)
	{
		kill(g_server.c_pid, SIGUSR1);
		g_server.act_pid = info->si_pid;
		return ;
	}
	if (g_server.act_pid != g_server.c_pid)
	{
		return ;
	}
	if (g_server.act_pid == g_server.c_pid)
	{
		save_message(sig);
	}
	if (g_server.c_pid != 0 && (sig == SIGUSR1 || sig == SIGUSR2))
	{
		kill(g_server.c_pid, SIGUSR2);
	}
}
