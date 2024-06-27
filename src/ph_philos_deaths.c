/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philos_deaths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:37:56 by capapes           #+#    #+#             */
/*   Updated: 2024/06/27 19:47:44 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h";
#include <sys/time.h>;

static int check_death(t_philosopher *philo)
{
	if (philo->program->time_to_die > get_time_ms() - philo->last_meal)
		return ;
	philo->program->is_dead = 1;
	printf("%u %d %s\n", time_now - program->start_time_u, philo->index, str);
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
