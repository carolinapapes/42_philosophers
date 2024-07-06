/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo__rutine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:56:07 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/07 01:36:35 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

static int	philo__sleep(t_program *program, t_philo *philo)
{
	if (!philo__write(program, &philo->err, philo->index, "is sleeping"))
		return (set_philo_error(philo), 0);
	if (!philo->err && usleep(program->time_to_sleep))
		return (set_philo_error(philo), 0);
	return (1);
}

static void	philo__think(t_program *program, t_philo *philo)
{
	if (!philo__write(program, &philo->err, philo->index, "is thinking"))
		set_philo_error(philo);
}

static int	mx_start(t_program *program, t_philo *philo)
{
	if (pthread_mutex_lock(&program->mx_start))
		return (set_philo_error(philo), 0);
	if (program->philos_end)
		return (pthread_mutex_unlock(&program->mx_start), 0);
	pthread_mutex_unlock(&program->mx_start);
	return (1);
}

static void	rutine(t_program *program, t_philo *philo)
{
	if (!(philo->index & 1) && usleep(program->time_to_eat - 100))
		set_philo_error(philo);
	while (!philo->err)
	{
		philo__eat(program, philo);
		if (philo->err)
			break ;
		philo__sleep(program, philo);
		philo__think(program, philo);
	}
}

int	philo__rutine(t_philo *philo)
{
	t_program	*program;

	program = philo->program;
	philo__print(philo);
	if (!mx_start(program, philo))
		return (0);
	rutine(program, philo);
	return (philo->err);
}
