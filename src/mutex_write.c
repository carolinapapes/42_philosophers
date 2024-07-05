/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:23:11 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/05 22:47:25 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

void	philo__write(t_program *program, int *i, int index, char *str)
{
	pthread_mutex_lock(&program->mx_write);
	if (program->philos_end)
	{
		*i = 0;
		pthread_mutex_unlock(&program->mx_write);
		return ;
	}
	printf("%ld %d %s\n", (get_time() - \
		program->time_start) / 1000, index, str);
	pthread_mutex_unlock(&program->mx_write);
}

void	program__write(t_program *program, int j)
{
	printf("%ld %d died\n", (get_time() - \
			program->time_start) / 1000, j);
}
