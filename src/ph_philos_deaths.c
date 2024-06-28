/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philos_deaths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:37:56 by capapes           #+#    #+#             */
/*   Updated: 2024/06/28 15:05:05 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <sys/time.h>
#include <stdio.h>

static void check_death(t_philosopher *philo)
{
	unsigned long int	time_u;
	
	ph_get_timeof_day_u(&time_u);
	if (philo->program->time_to_die > time_u - philo->last_meal)
		return ;
	philo->program->is_dead = 1;
	printf("%lu %d %s\n", (time_u - philo->program->start_time_u), philo->index, "died");
}

void    ph_philos__deaths(t_philosopher *philos)
{
	int i;

	i = -1;
	while (++i < philos->program->n_philosophers && !philos->program->is_dead)
	{
		usleep(2);
		pthread_mutex_lock(&philos->program->write);
		check_death(&philos[i]);
		pthread_mutex_unlock(&philos->program->write);
	}	
}
