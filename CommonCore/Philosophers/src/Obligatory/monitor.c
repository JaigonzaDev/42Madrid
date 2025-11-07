/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:44:16 by jaigonza          #+#    #+#             */
/*   Updated: 2025/10/07 15:44:01 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	meals_count(t_stadistics *stadistics, int i, int *total)
{
	pthread_mutex_lock(&stadistics->mutex.philosophers[i]);
	if (stadistics->philosophers[i].must_eat
		>= stadistics->rules.number_of_times_each_philosopher_must_eat)
		(*total)++;
	pthread_mutex_unlock(&stadistics->mutex.philosophers[i]);
}

int	check_meals(t_stadistics *stadistics)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	if (stadistics->rules.number_of_times_each_philosopher_must_eat == -1
		|| stadistics->rules.number_of_philosophers == 1)
		return (0);
	while (i < stadistics->rules.number_of_philosophers)
	{
		meals_count(stadistics, i, &total);
		i++;
	}
	if (total >= stadistics->rules.number_of_philosophers)
	{
		pthread_mutex_lock(&stadistics->mutex.dead);
		stadistics->dead = 1;
		pthread_mutex_unlock(&stadistics->mutex.dead);
		return (1);
	}
	return (0);
}

void	dead_philo(t_stadistics *stadistics, int i, time_t time)
{
	pthread_mutex_unlock(&stadistics->mutex.philosophers[i]);
	pthread_mutex_lock(&stadistics->mutex.dead);
	stadistics->dead = 1;
	pthread_mutex_unlock(&stadistics->mutex.dead);
	pthread_mutex_lock(&stadistics->mutex.priority);
	printf("%ld %d died.\n", time - stadistics->start_time,
		stadistics->philosophers[i].id);
	pthread_mutex_unlock(&stadistics->mutex.priority);
}

int	check_dead(t_stadistics *stadistics)
{
	int		i;
	time_t	time;

	time = 0;
	i = 0;
	while (i < stadistics->rules.number_of_philosophers)
	{
		get_ms(&time);
		pthread_mutex_lock(&stadistics->mutex.philosophers[i]);
		if ((time - stadistics->philosophers[i].last_meal_time)
			> stadistics->rules.time_to_die)
		{
			dead_philo(stadistics, i, time);
			return (1);
		}
		pthread_mutex_unlock(&stadistics->mutex.philosophers[i]);
		i++;
	}
	return (0);
}

void	*monitor(void *stadistics)
{
	t_stadistics	*stats;

	stats = (t_stadistics *)stadistics;
	while (1)
	{
		if (check_dead(stats) == 1 || check_meals(stadistics) == 1)
			return (NULL);
		ft_usleep(1);
	}
}
