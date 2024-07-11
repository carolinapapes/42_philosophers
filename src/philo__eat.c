/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo__eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:46:44 by capapes           #+#    #+#             */
/*   Updated: 2024/07/11 17:57:21 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

inline int	mx_lock(t_philo *philo, pthread_mutex_t *mutex, int err)
{
	return (pthread_mutex_lock(mutex) && exit_(philo, err));
}

static inline int	mx_forks__get(t_philo *philo, t_program *program)
{
	return (\
		mx_lock(philo, &philo->mx_fork_r, CLEAN__NONE) || \
		printf_e(program, philo, "takes fork", CLEAN__FORK_R) || \
		mx_lock(philo, philo->mx_fork_l, CLEAN__FORK_R) || \
		printf_e(program, philo, "takes fork", CLEAN__FORKS) \
	);
}

static inline int	mx_forks__drop(t_philo *philo)
{
	return (pthread_mutex_unlock(philo->mx_fork_l) | \
			pthread_mutex_unlock(&philo->mx_fork_r));
}

static inline int	mx_meal__set(t_philo *philo, t_program *program)
{
	if (pthread_mutex_lock(&philo->mx_meal))
		return (exit_(philo, CLEAN__FORKS));
	philo->meal_n++;
	philo->meal_t = get_time() - program->time_start;
	pthread_mutex_unlock(&philo->mx_meal);
	return (0);
}

static inline int	mx_meal__put(t_philo *philo, t_program *program)
{
	return (\
		mx_lock(philo, &program->mx_write, CLEAN__FORKS) || \
		((program->philos_end || \
		print_action(philo->meal_t / 1000, philo->index, "is eating") == -1) | \
		pthread_mutex_unlock(&program->mx_write) \
		&& exit_(philo, CLEAN__FROM_PUT)));
}

static inline int	mx_meal__exec(t_philo *philo, t_program *program)
{
	return (philo__usleep(philo, program->time_to_eat, CLEAN__FORKS));
}

int	philo__eat(t_program *program, t_philo *philo)
{
	return (\
			mx_forks__get(philo, program) || \
			mx_meal__set(philo, program) || \
			mx_meal__put(philo, program) || \
			mx_meal__exec(philo, program) || \
			mx_forks__drop(philo));
}

// static inline int	mx_meal__put(t_philo *philo, t_program *program)
// {
// 	if (mx_lock(philo, &program->mx_write, CLEAN__FORKS)) 
// 		return (1);
// 	if (program->philos_end)
// 		return (exit_(philo, CLEAN__FROM_PUT));
// 	if (print_action(philo->meal_t / 1000, philo->index, "is eating") == -1)
// 		return (exit_(philo, CLEAN__FROM_PUT));
// 	if (pthread_mutex_unlock(&program->mx_write))
// 		return (exit_(philo, CLEAN__FROM_PUT));
// 	return (0);
// }