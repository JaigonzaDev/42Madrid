/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:30:38 by jaigonza          #+#    #+#             */
/*   Updated: 2025/10/07 15:23:39 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
 * Check if the number of arguments is correct.
 */
int	checker(int argc)
{
	if (argc != 5 && argc != 6)
	{
		printf("error arguments\n Number if philo, time to die, time to eat,\
			time to sleep, number of times each should eat \n");
		return (0);
	}
	return (1);
}

/*
 * Just assign the id for the pthread_t (unsigned long)
 * Assign memory for all philo and assign it to the globals stats for control.
 * Create the threads and join them.
 */
void	create_table(t_stadistics *stadistics)
{
	init_mutex(stadistics);
	init_philo(stadistics);
}

int	start_dinner(t_stadistics *stadistics)
{
	int			i;
	pthread_t	mon;

	i = 0;
	while (i < stadistics->rules.number_of_philosophers)
	{
		if (pthread_create(&stadistics->philosophers[i].thread, NULL,
				philosopher, &stadistics->philosophers[i]))
			return (1);
		i++;
	}
	if (pthread_create(&mon, NULL, monitor, stadistics))
		return (1);
	i = 0;
	while (i < stadistics->rules.number_of_philosophers)
	{
		pthread_join(stadistics->philosophers[i].thread, NULL);
		i++;
	}
	pthread_join(mon, NULL);
	return (0);
}

void	clean_table(t_stadistics *stadistics)
{
	int	i;

	i = 0;
	while (i < stadistics->rules.number_of_philosophers)
	{
		pthread_mutex_destroy(&stadistics->mutex.forks[i]);
		pthread_mutex_destroy(&stadistics->mutex.philosophers[i]);
		i++;
	}
	free(stadistics->mutex.forks);
	free(stadistics->mutex.philosophers);
	free(stadistics->philosophers);
}

int	main(int argc, char **argv)
{
	t_stadistics	stadistics;

	if (!checker(argc))
		return (1);
	init_rules(argc, argv, &stadistics.rules);
	create_table(&stadistics);
	if (start_dinner(&stadistics))
		return (1);
	clean_table(&stadistics);
	return (0);
}
