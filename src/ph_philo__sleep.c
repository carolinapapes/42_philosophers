/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:23:57 by carolinapap       #+#    #+#             */
/*   Updated: 2024/06/30 03:26:42 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"

void	ph_philo__sleep(t_philosopher *philo)
{
	if (philo->program->is_dead)
		return ;
	ph_philo__write(philo, "Is sleeping");
	usleep(philo->program->time_to_sleep);
}
