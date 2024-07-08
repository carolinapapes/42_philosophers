/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo__rutine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:56:07 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/07 03:59:29 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

static int	philo__sleep(t_program *program, t_philo *philo)
{
	if (!philo__write(program, philo, "is sleeping"))
		return (exit_err(philo, CLEAN__NONE));
	if (!philo->err && usleep(program->time_to_sleep))
		return (exit_err(philo, CLEAN__NONE));
	return (0);
}

static int	philo__think(t_program *program, t_philo *philo)
{
	if (!philo__write(program, philo, "is thinking"))
		return (exit_err(philo, CLEAN__NONE));
	return (0);
}

static int	mx_start(t_program *program, t_philo *philo)
{
	if (pthread_mutex_lock(&program->mx_start))
		return (exit_err(philo, CLEAN__NONE));
	if (program->philos_end || \
		pthread_mutex_unlock(&program->mx_start))
		return (exit_err(philo, CLEAN__MX_START));
	return (0);
}

static void	rutine(t_program *program, t_philo *philo)
{
	if ((!philo->err) & philo->index & 1 \
		&& usleep(program->time_to_eat - 100))
		exit_err(philo, CLEAN__NONE);
	while (!philo->err || \
			!philo__eat(program, philo) || \
			!philo__sleep(program, philo) || \
			!philo__think(program, philo))
		;
}

int	philo__rutine(t_philo *philo)
{
	mx_start(philo->program, philo);
	rutine(philo->program, philo);
	return (philo->err);
}

	// philo__print(philo);