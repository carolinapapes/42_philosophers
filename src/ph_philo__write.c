/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:14:55 by carolinapap       #+#    #+#             */
/*   Updated: 2024/06/30 15:18:14 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <stdio.h>

void	ph_philo__write(t_philosopher *philo, char *str)
{
	unsigned long int	time_now;
	unsigned long int	time_diff;

	if (philo->program->is_dead)
		return ;
	pthread_mutex_lock(&philo->program->write);
	ph_get_timeof_day_u(&time_now);
	time_diff = (time_now - philo->program->start_time_u) * 0.001;
	if (!philo->program->is_dead)
		printf("[%lu]\t\t%d\t%s\n", time_diff, philo->index + 1, str);
	pthread_mutex_unlock(&philo->program->write);
}
