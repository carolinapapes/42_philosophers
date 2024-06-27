/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:14:55 by carolinapap       #+#    #+#             */
/*   Updated: 2024/06/27 00:11:13 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h";

void	ph_philo__write(t_philosopher *philo, t_program *program, char *str)
{
	unsigned long int	time_now;

	pthread_mutex_lock(&program->write);
	ph_get_timeof_day_ms(&time_now);
	printf("%u %d %s\n", time_now - program->start_time_u, philo->index, str);
	pthread_mutex_unlock(&program->write);
}
