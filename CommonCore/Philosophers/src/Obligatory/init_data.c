/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:38:55 by jaigonza          #+#    #+#             */
/*   Updated: 2025/10/07 14:48:26 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
 * Initialize with args.
 */
void	init_rules(int argc, char **argv, t_data *data)
{
	if (argc >= 5)
	{
		data->number_of_philosophers = atoi(argv[1]);
		data->time_to_die = atoi(argv[2]);
		data->time_to_eat = atoi(argv[3]);
		data->time_to_sleep = atoi(argv[4]);
		data->number_of_times_each_philosopher_must_eat = -1;
	}
	if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = atoi(argv[5]);
}

void	init_mutex(t_stadistics *stadistics)
{
	int	i;

	stadistics->mutex.forks = malloc(sizeof(pthread_mutex_t)
			* stadistics->rules.number_of_philosophers);
	if (!stadistics->mutex.forks)
		exit(1);
	stadistics->mutex.philosophers = malloc(sizeof(pthread_mutex_t)
			* stadistics->rules.number_of_philosophers);
	if (!stadistics->mutex.philosophers)
		exit(1);
	i = 0;
	while (i < stadistics->rules.number_of_philosophers)
	{
		pthread_mutex_init(&stadistics->mutex.forks[i], NULL);
		pthread_mutex_init(&stadistics->mutex.philosophers[i], NULL);
		i++;
	}
	pthread_mutex_init(&stadistics->mutex.dead, NULL);
	pthread_mutex_init(&stadistics->mutex.priority, NULL);
}

void	init_philo(t_stadistics *stadistics)
{
	int	i;

	stadistics->dead = 0;
	stadistics->philosophers = malloc(sizeof(t_philosopher)
			* stadistics->rules.number_of_philosophers);
	if (!stadistics->philosophers)
		exit(1);
	i = 0;
	get_ms(&stadistics->start_time);
	while (i < stadistics->rules.number_of_philosophers)
	{
		stadistics->philosophers[i].id = i + 1;
		stadistics->philosophers[i].last_meal_time = stadistics->start_time;
		stadistics->philosophers[i].must_eat = 0;
		stadistics->philosophers[i].left_fork = &stadistics->mutex.forks[i];
		stadistics->philosophers[i].right_fork = &stadistics->mutex.forks[(i
				+ 1) % stadistics->rules.number_of_philosophers];
		stadistics->philosophers[i].stadistics = stadistics;
		i++;
	}
}
