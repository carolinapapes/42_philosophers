/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:14:55 by carolinapap       #+#    #+#             */
/*   Updated: 2024/06/28 15:02:01 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <stdio.h>

void	ph_philo__write(t_philosopher *philo, char *str)
{
	unsigned long int	time_now;

	pthread_mutex_lock(&philo->program->write);
	ph_get_timeof_day_u(&time_now);
	printf("%lu %d %s\n", time_now - philo->program->start_time_u, philo->index, str);
	pthread_mutex_unlock(&philo->program->write);
}
