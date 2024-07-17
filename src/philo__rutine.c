/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo__rutine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:56:07 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/17 19:44:28 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo.h"
#include "philo_helpers.h"

static inline void	_start(t_program *program, t_philo *philo)
{
	((pthread_mutex_lock(&program->mx_start) || \
	philo__mx_lock(philo, &program->mx_write, PHILO_ERRR) || \
	program->philos_end | \
	philo__mx_unlock(philo, &program->mx_write, PHILO_ERRR) | \
	pthread_mutex_unlock(&program->mx_start)) || \
	(philo->index & 1 \
	&& philo__usleep(philo, program->time_to_eat - 900, PHILO_ERRR))) \
	&& exit_(philo, PHILO_ERRR);
}

static inline int	_sleep(t_program *program, t_philo *philo)
{
	return (\
		action__now(program, philo, SLEEP, PHILO_ERRR) || \
		philo__usleep(philo, program->time_to_sleep, PHILO_ERRR));
}

static inline int	_think(t_program *program, t_philo *philo)
{
	return (action__now(program, philo, "is thinking", PHILO_ERRR));
}

static inline int	_eat(t_program *program, t_philo *philo)
{
	return (\
		forks__get(philo, program) || \
		philo__meal(philo, program) || \
		forks__drop(philo));
}

void	philo__rutine(t_philo *philo)
{
	t_program	*program;

	program = philo->program;
	_start(program, philo);
	while (!philo->err && \
		!_eat(program, philo) && \
		!_sleep(program, philo) && \
		!_think(program, philo))
		;
}
