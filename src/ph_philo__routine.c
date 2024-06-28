/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:19:00 by capapes           #+#    #+#             */
/*   Updated: 2024/06/28 17:16:50 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ph_philosophers.h"

void	ph_philo__routine(t_philosopher *philo)
{
	// printf("aaaaaaaaaa\n");
	ph_philo__prethink(philo);

	while (1)
	{
		ph_philo__eat(philo);
		ph_philo__sleep(philo);
		ph_philo__think(philo);
	}
}