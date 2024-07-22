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

static int	done(t_philo *philo, t_program *program, int *k)
{
	return (program->meals_n != -1
		&& philo->meal_n >= program->meals_n
		&& ++(*k) >= program->philos_n);
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

static inline int	get_status(t_program *program, t_philo *philo, \
				long int time, int *k)
{
	return (
		(philo->err || dead(philo, time) || done(philo, program, k))
		&& end(program, k, philo->index));
}

int	program_status(t_program *program, t_philo *philo, \
				long int time, int *k)
{
	return (
		pthread_mutex_lock(&program->mx_write)
		|| get_status(program, philo, time, k)
		| pthread_mutex_unlock(&program->mx_write));
}