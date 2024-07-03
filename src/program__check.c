/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program__check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:07:15 by capapes           #+#    #+#             */
/*   Updated: 2024/07/03 21:22:53 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <unistd.h>



void	philo__mx_checkdeaths(t_program *program)
{
	int		i;
	int		j;
	int		k;
	t_philo	*philo;

	i = 1;
	while (i)
	{
		j = -1;
		k = 0;
		while (++j < program->philos_n)
		{
			philo = &program->philos[j];
			pthread_mutex_lock(&philo->mx_meal);
			if (philo->meal_t + program->time_to_die < \
				get_time() - program->time_start)
			{
				pthread_mutex_lock(&program->mx_write);
				printf("%ld %d died\n", (get_time() - \
					program->time_start) / 1000, philo->index);
				program->philos_end = 1;
				i = 0;
				pthread_mutex_unlock(&program->mx_write);
				pthread_mutex_unlock(&philo->mx_meal);
				break ;
			}
			if (philo->meal_n == program->meals_n)
				k++;
			pthread_mutex_unlock(&philo->mx_meal);
		}
		if (k == program->philos_n)
		{
			pthread_mutex_lock(&program->mx_write);
			program->philos_end = 1;
			i = 0;
			pthread_mutex_unlock(&program->mx_write);
		}
	}
}
