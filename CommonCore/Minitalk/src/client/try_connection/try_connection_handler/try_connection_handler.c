/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_connection_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:32:11 by jaigonza          #+#    #+#             */
/*   Updated: 2025/06/28 14:46:47 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	try_connection_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (info->si_pid == getpid())
	{
		ft_printf("Own process error\n");
		exit(1);
	}
	if (info->si_pid != g_client.pid)
	{
		ft_printf("pid error\n");
	}
	if (sig == SIGUSR1)
	{
		g_client.ok = 1;
	}
	else if (sig == SIGUSR2)
	{
		ft_printf("Server busy, retrying...\n");
		g_client.ok = 0;
	}
}
