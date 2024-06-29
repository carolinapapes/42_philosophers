/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:14:55 by carolinapap       #+#    #+#             */
/*   Updated: 2024/06/29 23:57:14 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <stdio.h>

void	ph_philo__write(t_philosopher *philo, char *str)
{
	unsigned long long	time_now;
	unsigned long long	time_diff;

	if (philo->program->is_dead)
		return ;
	pthread_mutex_lock(&philo->program->write);
	ph_get_timeof_day_u(&time_now);
	time_diff = (time_now - philo->program->start_time_u) * 0.001;
	printf("PHILO %d\t\t%llu\t%s\n", philo->index, time_diff, str);
	pthread_mutex_unlock(&philo->program->write);
}

