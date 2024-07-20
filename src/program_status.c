/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:07:15 by capapes           #+#    #+#             */
/*   Updated: 2024/07/18 17:12:32 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>
#include <stdio.h>

static inline int	dead(t_philo *philo, long int time)
{
	return (philo->meal_t < get_time() - time);
}

static inline int	done(t_philo *philo, t_program *program, int *k)
{
	return (philo->meal_n == program->meals_n && ++(*k) == program->philos_n);
}

static inline int	err(t_philo *philo)
{
	return (philo->err);
}

static int	end(t_program *program, int *k, int j)
{
	if (program->philos_end)
		return (0);
	program->philos_end = 1;
	if (program->philos_n != *k)
		printf("%ld %d died\n", (get_time() - program->time_start) / 1000, j);
	return (0);
}

int	program_status(t_program *program, t_philo *philo, \
				long int time, int *k)
{
	return ((\
		pthread_mutex_lock(&program->mx_write) || \
		((dead(philo, time) || done(philo, program, k) || err(philo)) \
		&& end(program, k, philo->index))) | \
		pthread_mutex_unlock(&program->mx_write));
}
