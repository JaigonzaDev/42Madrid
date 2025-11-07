/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:33:50 by jaigonza          #+#    #+#             */
/*   Updated: 2025/06/28 14:48:29 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_config(void)
{
	struct sigaction	confirm;
	sigset_t			sigset;

	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	confirm.sa_flags = SA_SIGINFO;
	confirm.sa_sigaction = send_message_handler;
	sigaction(SIGUSR1, &confirm, NULL);
	sigaction(SIGUSR2, &confirm, NULL);
}
