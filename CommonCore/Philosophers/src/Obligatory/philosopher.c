/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:33:24 by jaigonza          #+#    #+#             */
/*   Updated: 2025/10/07 14:43:10 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_lock(t_philosopher *philo, char *str)
{
	time_t	time;

	get_ms(&time);
	pthread_mutex_lock(&philo->stadistics->mutex.priority);
	pthread_mutex_lock(&philo->stadistics->mutex.dead);
	if (philo->stadistics->dead == 0)
		printf("%ld %d %s\n", time - philo->stadistics->start_time, philo->id,
			str);
	pthread_mutex_unlock(&philo->stadistics->mutex.dead);
	pthread_mutex_unlock(&philo->stadistics->mutex.priority);
}

void	take_forks(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_lock(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_lock(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_lock(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_lock(philo, "has taken a fork");
	}
}

void	routine(t_philosopher *philo)
{
	if (philo->stadistics->rules.number_of_philosophers == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_lock(philo, "has taken a fork");
		while (philo->stadistics->dead == 0)
			usleep(100);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	take_forks(philo);
	pthread_mutex_lock(&philo->stadistics->mutex.philosophers[philo->id - 1]);
	print_lock(philo, "is eating");
	get_ms(&philo->last_meal_time);
	philo->must_eat++;
	pthread_mutex_unlock(&philo->stadistics->mutex.philosophers[philo->id - 1]);
	ft_usleep(philo->stadistics->rules.time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	print_lock(philo, "is sleeping");
	ft_usleep(philo->stadistics->rules.time_to_sleep);
	print_lock(philo, "is thinking");
}

/*
 * Pass void statdistics because pthread_create only accept void *.
 * And then cast it to t_stadistics.
 * get_id is called to get the id of the philosopher.
 * Stats are global so if some philo is dead just change stats.dead.
 */
void	*philosopher(void *stadistics)
{
	t_philosopher	*philo;
	t_stadistics	*stats;

	philo = (t_philosopher *)stadistics;
	stats = philo->stadistics;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (1)
	{
		pthread_mutex_lock(&stats->mutex.dead);
		if (stats->dead == 1)
		{
			pthread_mutex_unlock(&stats->mutex.dead);
			return (NULL);
		}
		pthread_mutex_unlock(&stats->mutex.dead);
		routine(philo);
	}
	return (NULL);
}
