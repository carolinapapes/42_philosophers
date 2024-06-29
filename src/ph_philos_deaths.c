/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philos_deaths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:37:56 by capapes           #+#    #+#             */
/*   Updated: 2024/06/30 00:10:53 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <sys/time.h>
#include <stdio.h>

static void check_death(t_philosopher *philo)
{
	unsigned long long	time_u;
	unsigned long long	last_meal;
	
	ph_get_timeof_day_u(&time_u);
	if (philo->last_meal)
		last_meal = philo->last_meal;
	else
		last_meal = philo->program->start_time_u; 
	if (time_u < last_meal + philo->program->time_to_die)
		return ;
	philo->program->is_dead = 1;
	printf("PHILO %d\t\t%llu\tDIED -------------💀\n", philo->index, (time_u - last_meal)/1000);
}

void    ph_philos__deaths(t_program *program)
{
	int i;

	while (!program->is_dead)
	{
		usleep(10000);
		pthread_mutex_lock(&program->write);
		i = -1;
		while (++i < program->n_philosophers)
			check_death(&program->philos[i]);
		pthread_mutex_unlock(&program->write);
		
	}	
}
