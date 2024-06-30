/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:19:00 by capapes           #+#    #+#             */
/*   Updated: 2024/06/30 22:06:58 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"

void	ph_philo__routine(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->program->start);
	// should return if failed
	pthread_mutex_unlock(&philo->program->start);
	// should return if failed
	ph_philo__prethink(philo);
	while (!(philo->program->is_dead))
	{
		ph_philo__eat(philo);
		if (philo->program->is_dead || !philo->left_fork)
			break ;
		ph_philo__sleep(philo);
		ph_philo__think(philo);
	}
}
