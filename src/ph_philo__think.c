/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:27:50 by carolinapap       #+#    #+#             */
/*   Updated: 2024/06/30 03:26:37 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <sys/time.h>

void	ph_philo__prethink(t_philosopher *philo)
{
	if (philo->index % 2 == 0)
		usleep(philo->program->time_to_eat);
}

inline void	ph_philo__think(t_philosopher *philo)
{
	ph_philo__write(philo, "Is thinking");
}
