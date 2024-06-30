/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philos_deaths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:37:56 by capapes           #+#    #+#             */
/*   Updated: 2024/06/30 15:38:19 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <sys/time.h>
#include <stdio.h>


// static void get_last_meal(t_philosopher *philo, unsigned long int *last_meal)
// {
// 	if (philo->last_meal)
// 		*last_meal = philo->last_meal + philo->program->time_to_die;
// 	else
// 		*last_meal = philo->program->start_time_u + philo->program->time_to_die;
// }

static void	check_death(t_philosopher *philo)
{
	unsigned long int	time_u;
	// unsigned long int	last_meal;

	ph_get_timeof_day_u(&time_u);
	// get_last_meal(philo, &last_meal);
	if (time_u - philo->program->start_time_u\
	< philo->last_meal + philo->program->time_to_die)
		return ;
	philo->program->is_dead = 1;
	printf("[%lu]\t%d\tDIED -------------💀\n", \
	(time_u - philo->program->start_time_u) / 1000,	philo->index + 1);
}

void ph_philos__meals(t_program *program)
{
	int	i;

	while (!program->is_dead)
	{
		usleep(2000);
		pthread_mutex_lock(&program->write);
		i = -1;
		while (++i < program->n_philosophers && !program->is_dead)
		{
			if (program->n_meals > program->philos[i].meals)
				break;
			if (i == program->n_philosophers - 1)
				program->is_dead = 1;
		}
		pthread_mutex_unlock(&program->write);
	}
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
		
		i = -1;
		while (program->n_meals != -1 && ++i < program->n_philosophers && !program->is_dead)
		{
			if (program->n_meals > program->philos[i].meals)
				break;
			if (i == program->n_philosophers - 1)
				program->is_dead = 1;
		}
		pthread_mutex_unlock(&program->write);
	}
}
