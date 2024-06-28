/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:27:50 by carolinapap       #+#    #+#             */
/*   Updated: 2024/06/27 20:22:00 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <sys/time.h>

void	ph_philo__prethink(t_philosopher *philo)
{
	if (philo->index % 2 == 0)
	{
		ph_philo__think(philo);
		usleep(philo->program->time_to_eat - 10);
	}
}

inline void	ph_philo__think(t_philosopher *philo)
{
	ph_philo__write(philo, "is thinking");
}
