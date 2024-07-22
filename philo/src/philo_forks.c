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
	int		i;

	i = 0;
	while (&philo->mx_fork_r == philo->mx_fork_l && !philo->err)
	{
		usleep(1);
		philo_mx_lock(philo, &program->mx_write, PHILO_ERR_FORK_LEFT);
		if (program->philos_end)
			i = 1;
		philo_mx_unlock(philo, &program->mx_write, PHILO_ERR_FORK_LEFT);
		if (i)
			return (philo_exit_print(philo, PHILO_ERR_FORK_LEFT));
	}
	return (0);
}

inline int	forks_get(t_philo *philo, t_program *program)
{
	if (philo->program->rutine && philo->index & 1)
		return (
			philo_mx_lock(philo, philo->mx_fork_l, PHILO_ERRR)
			|| action_now(program, philo, "takes fork", PHILO_ERR_FORK_LEFT)
			|| check_dead(philo, program)
			|| philo_mx_lock(philo, &philo->mx_fork_r, PHILO_ERR_FORK_LEFT)
			|| action_now(program, philo, "takes fork", PHILO_ERR_FORKS_L)
		);
	return (
		philo_mx_lock(philo, &philo->mx_fork_r, PHILO_ERRR)
		|| action_now(program, philo, "takes fork", PHILO_ERR_FORK_RIGHT)
		|| check_dead(philo, program)
		|| philo_mx_lock(philo, philo->mx_fork_l, PHILO_ERR_FORK_RIGHT)
		|| action_now(program, philo, "takes fork", PHILO_ERR_FORKS_R)
	);
}

inline int	forks_drop(t_philo *philo)
{
	if (philo->program->rutine && philo->index & 1)
		return (
			philo_mx_unlock(philo, philo->mx_fork_l, PHILO_ERRR)
			| philo_mx_unlock(philo, &philo->mx_fork_r, PHILO_ERRR));
	return (
		philo_mx_unlock(philo, &philo->mx_fork_r, PHILO_ERRR)
		| philo_mx_unlock(philo, philo->mx_fork_l, PHILO_ERRR));
}

static int	next(t_philo *philo, t_program *program)
{
	philo->meal_n++;
	philo->meal_t = get_time() - program->time_start;
	return (philo->meal_t < 0);
}

static inline int take_meal(t_program *program, t_philo *philo)
{
	return (
		check_philo_end(program, philo)
		|| next(philo, program)
		|| action(philo->meal_t * 0.001, philo->index, EAT));
}

inline int	philo_meal(t_philo *philo, t_program *program)
{
	return (
		philo_mx_lock(philo, &program->mx_write, PHILO_ERRR)
		|| take_meal(program, philo) | philo_mx_unlock(philo, &program->mx_write, PHILO_ERR_WRITE)
		|| philo_usleep(philo, program->time_to_eat, PHILO_ERRR));
}

