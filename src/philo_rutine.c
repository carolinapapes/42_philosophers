/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rutine.c                                    :+:      :+:    :+:   */
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
	philo_mx_lock(philo, &program->mx_write, PHILO_ERRR) || \
	program->philos_end | \
	philo_mx_unlock(philo, &program->mx_write, PHILO_ERRR) | \
	pthread_mutex_unlock(&program->mx_start)) || \
	(philo->index & 1 \
	&& philo_usleep(philo, program->time_to_eat - 900, PHILO_ERRR))) \
	&& philo_exit(philo, PHILO_ERRR);
}

static inline int	_sleep(t_program *program, t_philo *philo)
{
	return (\
		action_now(program, philo, SLEEP, PHILO_ERRR) || \
		philo_usleep(philo, program->time_to_sleep, PHILO_ERRR));
}

static inline int	_think(t_program *program, t_philo *philo)
{
	return (action_now(program, philo, "is thinking", PHILO_ERRR));
}

static inline int	_eat(t_program *program, t_philo *philo)
{
	return (\
		forks_get(philo, program) || \
		philo_meal(philo, program) || \
		forks_drop(philo));
}

void	philo_rutine(t_philo *philo)
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
