/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:23:11 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/07 01:15:12 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

static inline int	print_action(t_program *program, int index, char *str)
{
	return (printf("%ld %d %s\n", \
		(get_time() - program->time_start) / 1000, index, str));
}

int	philo__write(t_program *program, int *i, int index, char *str)
{
	if (pthread_mutex_lock(&program->mx_write))
	{
		set_philo_error(&program->philos[index]);
		return (1);
	}
	if (program->philos_end)
		*i = 0;
	else
		print_action(program, index, str);
	pthread_mutex_unlock(&program->mx_write);
	return (0);
}

void	program__write(t_program *program, int j)
{
	printf("%ld %d died\n", (get_time() - \
			program->time_start) / 1000, j);
}
