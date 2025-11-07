/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:43:20 by jaigonza          #+#    #+#             */
/*   Updated: 2025/06/28 14:50:23 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	clean(void)
{
	if (g_server.message != NULL)
	{
		free(g_server.message);
		g_server.message = NULL;
	}
	ft_bzero(&g_server, sizeof(t_server));
}
