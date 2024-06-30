/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:27:50 by carolinapap       #+#    #+#             */
/*   Updated: 2024/06/30 22:06:56 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"

void	ph_philo__prethink(t_philosopher *philo)
{
	if (philo->index % 2 == 0)
		usleep(philo->program->time_to_eat);
		// should return if failed
}

inline void	ph_philo__think(t_philosopher *philo)
{
	ph_philo__write(philo, "is thinking");
}
