/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:19:00 by capapes           #+#    #+#             */
/*   Updated: 2024/06/30 01:46:56 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"

void	ph_philo__routine(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->program->start);
	pthread_mutex_unlock(&philo->program->start);
	ph_philo__prethink(philo);
	while (!(philo->program->is_dead))
	{
		ph_philo__eat(philo);
		ph_philo__sleep(philo);
		ph_philo__think(philo);
	}
}
