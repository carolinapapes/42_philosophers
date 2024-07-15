/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx__meals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:07:15 by capapes           #+#    #+#             */
/*   Updated: 2024/07/12 17:54:45 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>
#include <stdio.h>

static inline int	_dead(t_philo *philo, long int time)
{
	return (philo->meal_t < get_time() - time);
}

static inline int	_done(t_philo *philo, t_program *program, int *k)
{
	return (philo->meal_n == program->meals_n && ++(*k) == program->philos_n);
}

static inline int	_err(t_philo *philo)
{
	return (philo->err);
}

static int	_end(t_program *program, int *k, int j)
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
	return ((\
		pthread_mutex_lock(&philo->mx_meal) || \
		((_dead(philo, time) || _done(philo, program, k) || _err(philo)) \
		&& _end(program, k, philo->index))) | \
		pthread_mutex_unlock(&philo->mx_meal));
}
