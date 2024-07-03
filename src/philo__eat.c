/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo__eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:46:44 by capapes           #+#    #+#             */
/*   Updated: 2024/07/03 20:55:29 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

static void	take_forks(t_philo *philo, int *i, t_program *program, int index)
{
	pthread_mutex_lock(&philo->mx_fork_r);
	philo__write(program, i, index, "takes fork");
	pthread_mutex_lock(philo->mx_fork_l);
	philo__write(program, i, index, "takes fork");
}

static void	meal(t_philo *philo, int *i, t_program *program, int index)
{
	pthread_mutex_lock(&philo->mx_meal);
	pthread_mutex_lock(&program->mx_write);
	if (!program->philos_end)
	{
		philo->meal_n++;
		philo->meal_t = get_time() - program->time_start;
		printf("%ld %d is eating\n", philo->meal_t / 1000, index);
	}
	else
		*i = 0;
	pthread_mutex_unlock(&program->mx_write);
	pthread_mutex_unlock(&philo->mx_meal);
	if (*i)
		usleep(program->time_to_eat);
}

static void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->mx_fork_l);
	pthread_mutex_unlock(&philo->mx_fork_r);
}

void	philo__eat(t_philo *philo, int *i, t_program *program, int index)
{
	take_forks(philo, i, program, index);
	meal(philo, i, program, index);
	drop_forks(philo);
}
