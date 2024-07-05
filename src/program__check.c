/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program__check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:07:15 by capapes           #+#    #+#             */
/*   Updated: 2024/07/04 19:30:01 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

static inline int	is_dead(t_philo *philo, long int time)
{
	return (philo->meal_t < get_time() - time);
}

static inline int	is_done(t_philo *philo, t_program *program, int *k)
{
	return (philo->meal_n == program->meals_n && ++(*k) == program->philos_n);
}

static void	program__end(t_program *program, int *k, int j)
{
	pthread_mutex_lock(&program->mx_write);
	program->philos_end = 1;
	if (program->philos_n != *k)
		write__death(program, j);
	pthread_mutex_unlock(&program->mx_write);
}

int	philo__check(t_program *program, t_philo *philo, long int time, int *k)
{
	pthread_mutex_lock(&philo->mx_meal);
	if (is_dead(philo, time) || is_done(philo, program, k))
	{
		program__end(program, k, philo->index);
		pthread_mutex_unlock(&philo->mx_meal);
		return (1);
	}
	pthread_mutex_unlock(&philo->mx_meal);
	return (0);
}

void	program__check(t_program *program)
{
	int			j;
	int			k;
	long int	time;

	time = program->time_start + program->time_to_die;
	while (42)
	{
		j = -1;
		k = 0;
		while (++j < program->philos_n)
			if (philo__check(program, &program->philos[j], time, &k))
				return ;
	}
}
