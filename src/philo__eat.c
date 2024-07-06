/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo__eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:46:44 by capapes           #+#    #+#             */
/*   Updated: 2024/07/07 00:08:14 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#define FORK_GET 1
#define FORK_DROP 0

static int	mx_forks(t_philo *philo, t_program *program, int action)
{
	if (action == FORK_GET)
	{
		if (pthread_mutex_lock(&philo->mx_fork_r))
			return (exit_err(philo, CLEAN__NONE));
		if (philo__write(program, &philo->err, philo->index, "takes fork"))
			return (exit_err(philo, CLEAN__FORK_R));
		if (pthread_mutex_lock(philo->mx_fork_l))
			return (exit_err(philo, CLEAN__FORK_R));
		if (philo__write(program, &philo->err, philo->index, "takes fork"))
			return (exit_err(philo, CLEAN__FORKS));
		return (0);
	}
	pthread_mutex_unlock(philo->mx_fork_l);
	pthread_mutex_unlock(&philo->mx_fork_r);
	return (0);
}

static int	mx_meal__set(t_philo *philo, t_program *program)
{
	if (pthread_mutex_lock(&philo->mx_meal))
		return (exit_err(philo, CLEAN__FORKS));
	philo->meal_n++;
	philo->meal_t = get_time() - program->time_start;
	pthread_mutex_unlock(&philo->mx_meal);
	return (0);
}

static int	mx_meal__put(t_philo *philo, t_program *program)
{
	if (pthread_mutex_lock(&program->mx_write))
		return (exit_err(philo, CLEAN__FORKS));
	if (program->philos_end)
		return (exit_err(philo, CLEAN__FROM_PUT));
	if (printf("%ld %d is eating\n", philo->meal_t / 1000, philo->index) == -1)
		return (exit_err(philo, CLEAN__FROM_PUT));
	pthread_mutex_unlock(&program->mx_write);
	return (0);
}

static int	mx_meal__exec(t_philo *philo, t_program *program)
{
	if (!philo->err && usleep(program->time_to_eat))
		return (exit_err(philo, CLEAN__FORKS));
	return (0);
}

int	philo__eat(t_program *program, t_philo *philo)
{
	return (mx_forks(philo, program, FORK_GET) || \
			mx_meal__set(philo, program) || \
			mx_meal__put(philo, program) || \
			mx_meal__exec(philo, program) || \
			mx_forks(philo, program, FORK_DROP));
}
