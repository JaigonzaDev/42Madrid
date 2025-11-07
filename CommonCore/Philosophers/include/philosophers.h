/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:27:07 by jaigonza          #+#    #+#             */
/*   Updated: 2025/10/07 15:15:32 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

/*
 * 1. Program can recive 5 arguments
 * -> number_of_filosofers
 *      - Max ulimit.
 * -> time_to_die
 *      - In miliseconds.
 * -> time_to_eat
 *      - In miliseconds.
 * -> time_to_sleep
 *      - In miliseconds.
 * -> number_of_times_each_filosofer_must_eat
 *      - Stop with dead.
 */
typedef struct s_stadistics	t_stadistics;
typedef struct s_data
{
	int						number_of_philosophers;
	time_t					time_to_die;
	time_t					time_to_eat;
	time_t					time_to_sleep;
	int						number_of_times_each_philosopher_must_eat;
}							t_data;

typedef struct s_philosopher
{
	t_stadistics			*stadistics;
	int						id;
	pthread_t				thread;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	int						must_eat;
	time_t					last_meal_time;
}							t_philosopher;

typedef struct s_mutex
{
	pthread_mutex_t			*forks;
	pthread_mutex_t			*philosophers;
	pthread_mutex_t			dead;
	pthread_mutex_t			priority;
}							t_mutex;
typedef struct s_stadistics
{
	int						start;
	int						dead;
	t_philosopher			*philosophers;
	t_data					rules;
	time_t					start_time;
	t_mutex					mutex;
}							t_stadistics;

//-----------------------
void						init_mutex(t_stadistics *stadistics);
void						init_philo(t_stadistics *stadistics);
void						init_stadistics(t_stadistics *stadistics);
//-----------------------
void						*philosopher(void *stadistics);
// void get_id(t_stadistics *stadistics, int *position);
void						time_to_die_left(t_stadistics *stadistics,
								int position);
void						routine(t_philosopher *philo);
//-----------------------
void						*priority(void *stats);
//-----------------------
void						*check_id_ok(void *stats);
//-----------------------
void						start_thinking(t_stadistics *stadistics,
								int position);
void						start_sleeping(t_stadistics *stadistics,
								int position);
void						start_eating(t_stadistics *stadistics,
								int position);
//-----------------------

time_t						calculate_diff(time_t start, time_t end);
void						get_ms(time_t *time);

void						ft_usleep(long time);
void						*monitor(void *stadistics);
void						init_rules(int argc, char **argv, t_data *data);
#endif