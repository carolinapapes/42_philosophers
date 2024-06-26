/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:23:57 by carolinapap       #+#    #+#             */
/*   Updated: 2024/06/30 22:06:52 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"

void	ph_philo__sleep(t_philosopher *philo)
{
	if (philo->program->is_dead || !philo->left_fork)
		return ;
	ph_philo__write(philo, "is sleeping");
	usleep(philo->program->time_to_sleep);
	// should return if failed
}
