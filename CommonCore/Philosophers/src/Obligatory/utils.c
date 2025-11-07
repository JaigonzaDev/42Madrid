/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:32:51 by jaigonza          #+#    #+#             */
/*   Updated: 2025/10/07 14:44:01 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(long time)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

/*
 * Get the current time in miliseconds.
 * To get a reference of a global time.
 */
void	get_ms(time_t *time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	*time = (now.tv_sec * 1000) + (now.tv_usec / 1000);
}
