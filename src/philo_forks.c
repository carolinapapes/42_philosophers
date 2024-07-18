/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:46:44 by capapes           #+#    #+#             */
/*   Updated: 2024/07/18 17:49:27 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo.h"
#include "philo_helpers.h"
#include <unistd.h>

static inline int	check_dead(t_philo *philo, t_program *program)
{
	while (&philo->mx_fork_r == philo->mx_fork_l)
	{
		usleep(1);
		philo_mx_lock(philo, &program->mx_write, PHILO_ERR_FORK_LEFT);
		if (program->philos_end)
		{
			philo_exit(philo, PHILO_ERR_FORK_LEFT);
			return (1);
		}
		philo_mx_unlock(philo, &program->mx_write, PHILO_ERR_FORK_LEFT);
	}
	return (0);
}

inline int	forks_get(t_philo *philo, t_program *program)
{
	if (philo->program->rutine && philo->index & 1)
		return (\
			philo_mx_lock(philo, philo->mx_fork_l, PHILO_ERRR) || \
			action_now(program, philo, "takes fork", PHILO_ERR_FORK_LEFT) || \
			check_dead(philo, program) || \
			philo_mx_lock(philo, &philo->mx_fork_r, PHILO_ERR_FORK_LEFT) || \
			action_now(program, philo, "takes fork", PHILO_ERR_FORKS) \
		);
	return (\
		philo_mx_lock(philo, &philo->mx_fork_r, PHILO_ERRR) || \
		action_now(program, philo, "takes fork", PHILO_ERR_FORK_RIGHT) || \
		check_dead(philo, program) || \
		philo_mx_lock(philo, philo->mx_fork_l, PHILO_ERR_FORK_RIGHT) || \
		action_now(program, philo, "takes fork", PHILO_ERR_FORKS) \
	);
}

inline int	forks_drop(t_philo *philo)
{
	if (philo->program->rutine && philo->index & 1)
		return (philo_mx_unlock(philo, philo->mx_fork_l, PHILO_ERRR) | \
				philo_mx_unlock(philo, &philo->mx_fork_r, PHILO_ERRR));
	return (philo_mx_unlock(philo, &philo->mx_fork_r, PHILO_ERRR) | \
			philo_mx_unlock(philo, philo->mx_fork_l, PHILO_ERRR));
}

static int	next(t_philo *philo, t_program *program)
{
	philo->meal_n++;
	philo->meal_t = get_time() - program->time_start;
	return (philo->meal_t < 0);
}

inline int	philo_meal(t_philo *philo, t_program *program)
{
	return ((\
		philo_mx_lock(philo, &program->mx_write, PHILO_ERR_MEAL) || \
		check_philo_end(program, philo, PHILO_ERR_WRITE) || \
		next(philo, program) || \
		action(philo->meal_t * 0.001, philo->index, EAT) || \
		philo_mx_unlock(philo, &program->mx_write, PHILO_ERR_WRITE) || \
		philo_usleep(philo, program->time_to_eat, PHILO_ERRR)) \
		&& philo_exit(philo, PHILO_ERR_FORKS));
}
