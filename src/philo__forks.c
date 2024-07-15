/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo__forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:46:44 by capapes           #+#    #+#             */
/*   Updated: 2024/07/12 17:46:20 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo.h"
#include "philo_helpers.h"

inline int	forks__get(t_philo *philo, t_program *program)
{
	return (\
		mx_lock(philo, &philo->mx_fork_r, PHILO_ERRR) || \
		action__now(program, philo, "takes fork", PHILO_ERR_FORK_R) || \
		mx_lock(philo, philo->mx_fork_l, PHILO_ERR_FORK_R) || \
		action__now(program, philo, "takes fork", PHILO_ERR_FORKS) \
	);
}

inline int	forks__drop(t_philo *philo)
{
	return (mx_unlock(philo, philo->mx_fork_l, PHILO_ERRR) | \
			mx_unlock(philo, &philo->mx_fork_r, PHILO_ERRR));
}

static int	_next(t_philo *philo, t_program *program)
{
	philo->meal_n++;
	philo->meal_t = get_time() - program->time_start;
	return (philo->meal_t < 0);
}

inline int	philo__meal(t_philo *philo, t_program *program)
{
	return ((\
		mx_lock(philo, &program->mx_write, PHILO_ERRR) || \
		mx_lock(philo, &philo->mx_meal, PHILO_ERRR) || \
		check_philo_end(program, philo, PHILO_ERR_WRITE) || \
		_next(philo, program) || \
		action(philo->meal_t * 0.001, philo->index, EAT) || \
		mx_unlock(philo, &philo->mx_meal, PHILO_ERR_MEAL) || \
		mx_unlock(philo, &program->mx_write, PHILO_ERR_WRITE) || \
		philo__usleep(philo, program->time_to_eat, PHILO_ERRR)) \
		&& exit_(philo, PHILO_ERR_FORKS));
}
