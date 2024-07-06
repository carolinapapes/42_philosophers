/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx__meals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:07:15 by capapes           #+#    #+#             */
/*   Updated: 2024/07/07 01:31:55 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>
#include <stdio.h>

static inline int	is_dead(t_philo *philo, long int time)
{
	return (philo->meal_t < get_time() - time);
}

static inline int	is_done(t_philo *philo, t_program *program, int *k)
{
	return (philo->meal_n == program->meals_n && ++(*k) == program->philos_n);
}

static inline int	is_err(t_philo *philo)
{
	return (philo->err);
}

static int	mx__write_end(t_program *program, int *k, int j)
{
	int	should_unlock;

	should_unlock = 1;
	if (pthread_mutex_lock(&program->mx_write))
		should_unlock = 0;
	program->philos_end = 1;
	if (program->philos_n != *k)
		printf("%ld %d died\n", (get_time() - program->time_start) / 1000, j);
	if (should_unlock)
		pthread_mutex_unlock(&program->mx_write);
	return (1);
}

int	mx__meals(t_program *program, t_philo *philo, \
				long int time, int *k)
{
	if (pthread_mutex_lock(&philo->mx_meal))
		return (mx__write_end(program, k, philo->index));
	if (is_dead(philo, time) || is_done(philo, program, k) || is_err(philo))
		return (mx__write_end(program, k, philo->index));
	pthread_mutex_unlock(&philo->mx_meal);
	return (0);
}
