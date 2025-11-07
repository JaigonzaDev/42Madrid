/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:24:08 by jaigonza          #+#    #+#             */
/*   Updated: 2025/07/05 16:26:32 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_client	g_client;

int	check_args(int argc, char **argv)
{
	if (argc != 3 || !argv[2] || !(*argv[2]))
	{
		ft_printf("Uso: <PID> <Message>\n");
		return (0);
	}
	return (1);
}

void	init(char *str_pid, char *str_message)
{
	g_client.pid = ft_atoi(str_pid);
	if (g_client.pid <= 0)
	{
		ft_printf("Invalid PID: %s\n", str_pid);
		exit(1);
	}
	g_client.message = str_message;
}

int	main(int argc, char **argv)
{
	if (!check_args(argc, argv))
		return (1);
	init(argv[1], argv[2]);
	try_connection();
	ft_printf("Connected to server with PID: %d\n", g_client.pid);
	send_config();
	send_message(g_client.message, g_client.pid);
	return (0);
}
