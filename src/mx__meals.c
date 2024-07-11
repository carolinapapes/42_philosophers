/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx__meals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:07:15 by capapes           #+#    #+#             */
/*   Updated: 2024/07/11 17:59:25 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>
#include <stdio.h>

static inline int	is_dead(t_philo *philo, long int time)
{
	return (philo->meal_t < get_time() - time);
}

static inline int	is_done(t_philo *philo, t_program *program, int *k)
{
	return (philo->meal_n == program->meals_n && ++(*k) == program->philos_n);
}

static inline int	is_err(t_philo *philo)
{
	return (philo->err);
}

inline void	conditional_mutex_lock(pthread_mutex_t *mutex, int *should_unlock)
{
	*should_unlock = 1;
	if (pthread_mutex_lock(mutex))
		*should_unlock = 0;
}

inline void	conditional_mutex_unlock(pthread_mutex_t *mutex, int *should_unlock)
{
	if (should_unlock)
		pthread_mutex_unlock(mutex);
}

static inline void	set_dead(t_program *program, int j, int *k)
{
	program->philos_end = 1;
	if (program->philos_n != *k)
		printf("%ld %d died\n", (get_time() - program->time_start) / 1000, j);
}

static int	mx__write_end(t_program *program, int *k, int j)
{
	int	should_unlock;

	conditional_mutex_lock(&program->mx_write, &should_unlock);
	set_dead(program, j, k);
	conditional_mutex_unlock(&program->mx_write, &should_unlock);
	return (1);
}

int	mx__meals(t_program *program, t_philo *philo, \
				long int time, int *k)
{
	return (\
		(pthread_mutex_lock(&philo->mx_meal) || \
		(is_dead(philo, time) || is_done(philo, program, k) || is_err(philo)) | \
		pthread_mutex_unlock(&philo->mx_meal)) && \
		mx__write_end(program, k, philo->index));
}
