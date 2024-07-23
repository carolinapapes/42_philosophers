/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rutine_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:36:00 by capapes           #+#    #+#             */
/*   Updated: 2024/07/23 01:08:01 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo.h"
#include "philo_helpers.h"

static inline int	check_end(t_program *program, t_philo *philo)
{
	return (
		philo_mx_lock(philo, &program->mx_write, PHILO_ERRR)
		|| program->philos_end
		| philo_mx_unlock(philo, &program->mx_write, PHILO_ERRR));
}

static inline int	start(t_program *program, t_philo *philo)
{
	return (
		pthread_mutex_lock(&program->mx_start)
		|| check_end(program, philo)
		| pthread_mutex_unlock(&program->mx_start));
}

static inline int	delay_odd(t_program *program, t_philo *philo)
{
	return (philo->index & 1
		&& philo_usleep(philo, program->time_to_eat - 900, PHILO_ERRR));
}

inline void	set_start(t_program *program, t_philo *philo)
{
	(
		start(program, philo)
		|| delay_odd(program, philo)
	)
	&& philo_exit(philo, PHILO_ERRR);
}
