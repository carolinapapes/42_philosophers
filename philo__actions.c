/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo__actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:40:15 by capapes           #+#    #+#             */
/*   Updated: 2024/07/12 17:42:32 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philosophers.h"

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

void	philo__actions(t_program *program, t_philo *philo)
{
	while (!philo->err && \
			!_eat(program, philo) && \
			!_sleep(program, philo) && \
			!_think(program, philo))
		;
}
