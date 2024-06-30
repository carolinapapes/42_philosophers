/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philos_deaths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:37:56 by capapes           #+#    #+#             */
/*   Updated: 2024/06/30 21:09:56 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <sys/time.h>
#include <stdio.h>

static void	check_death(t_philosopher *philo)
{
	unsigned long int	time_u;

	ph_get_timeof_day_u(&time_u);
	if (philo->last_meal + philo->program->time_to_die > \
			time_u - philo->program->start_time_u)
		return ;
	philo->program->is_dead = 1;
	printf("[%lu]\t%d\tDIED -------------💀\n", \
		(time_u - philo->program->start_time_u) / 1000, philo->index + 1);
}

void	ph_philos__deaths(t_program *program)
{
	int	i;
	int	j;

	j = 0;
	while (!program->is_dead)
	{
		usleep(2000);
		pthread_mutex_lock(&program->write);
		i = -1;
		j = 0;
		while (++i < program->n_philosophers && !program->is_dead)
		{
			check_death(&program->philos[i]);
			if (program->n_meals && program->n_meals \
				<= program->philos[i].meals)
				j++;
			if (j == program->n_philosophers)
				program->is_dead = 1;
		}
		pthread_mutex_unlock(&program->write);
	}
}
