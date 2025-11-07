/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:52:24 by jaigonza          #+#    #+#             */
/*   Updated: 2025/06/28 14:51:26 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_config(void)
{
	struct sigaction	confirm;
	sigset_t			sigset;

	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	confirm.sa_flags = SA_SIGINFO | SA_RESTART;
	confirm.sa_sigaction = server_handler;
	confirm.sa_mask = sigset;
	sigaction(SIGUSR1, &confirm, NULL);
	sigaction(SIGUSR2, &confirm, NULL);
}
