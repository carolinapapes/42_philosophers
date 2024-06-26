/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philos_deaths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:37:56 by capapes           #+#    #+#             */
/*   Updated: 2024/06/26 20:34:46 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h";
#include <sys/time.h>;

static int check_death(t_philosopher *philo)
{
	if (philo->program->time_to_die < get_time_ms() - philo->last_meal)
	{
		philo->program->is_dead = 1;
		ph_philo__write(philo, philo->program, "died", 1);
	}
}

void    ph_philos__deaths(t_philosopher *philos)
{
	int i;

	i = -1;
	while (++i < philos->program->n_philosophers && !philos->program->is_dead)
	{
		usleep(2);
		check_death(&philos[i]);
	}	
}