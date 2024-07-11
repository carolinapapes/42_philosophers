/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo__rutine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:56:07 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/11 17:36:54 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

inline int	philo__usleep(t_philo *philo, int time, int err)
{
	return (philo->err || (usleep(time) && exit_(philo, err)));
}

static inline int	philo__sleep(t_program *program, t_philo *philo)
{
	return (philo__write(program, philo, "is sleeping") || \
			philo__usleep(philo, program->time_to_sleep, CLEAN__NONE));
}

static inline int	philo__think(t_program *program, t_philo *philo)
{
	return (philo__write(program, philo, "is thinking") \
			&& exit_(philo, CLEAN__NONE));
}

static inline void	mx_start(t_program *program, t_philo *philo)
{
	(pthread_mutex_lock(&program->mx_start) || \
	program->philos_end | \
	pthread_mutex_unlock(&program->mx_start)) \
	&& exit_(philo, CLEAN__NONE);
}

static inline void	odd_usleep(t_program *program, t_philo *philo)
{
	philo->index & 1 \
	&& philo__usleep(philo, program->time_to_eat, CLEAN__NONE)
	&& exit_(philo, CLEAN__NONE);
}

void	philo__rutine(t_philo *philo)
{
	t_program	*program;

	program = philo->program;
	mx_start(program, philo);
	odd_usleep(program, philo);
	while (!philo->err && \
			!philo__eat(program, philo) && \
			!philo__sleep(program, philo) && \
			!philo__think(program, philo))
		;
}
