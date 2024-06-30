/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philos_deaths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:37:56 by capapes           #+#    #+#             */
/*   Updated: 2024/06/30 03:30:39 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <sys/time.h>
#include <stdio.h>

static void	check_death(t_philosopher *philo)
{
	unsigned long int	time_u;
	unsigned long int	last_meal;

	ph_get_timeof_day_u(&time_u);
	if (philo->last_meal)
		last_meal = philo->last_meal;
	else
		last_meal = philo->program->start_time_u;
	if (time_u < last_meal + philo->program->time_to_die)
		return ;
	philo->program->is_dead = 1;
	printf("[%d]\t\t%lu\tDIED -------------💀\n", \
		philo->index, (time_u - philo->program->start_time_u) / 1000);
}

void	ph_philos__deaths(t_program *program)
{
	int	i;

	while (!program->is_dead)
	{
		usleep(2000);
		pthread_mutex_lock(&program->write);
		i = -1;
		while (++i < program->n_philosophers && !program->is_dead)
			check_death(&program->philos[i]);
		pthread_mutex_unlock(&program->write);
	}
}
