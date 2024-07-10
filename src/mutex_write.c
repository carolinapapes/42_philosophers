/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:23:11 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/08 23:46:24 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

static inline int	print_action(unsigned long time, int index, char *str)
{
	return (printf("%ld %d %s\n", time, index, str));
}

static inline int	print_action__now(t_program *program, int index, char *str)
{
	return (print_action(get_time() - program->time_start, index, str));
}

int	philo__write(t_program *program, t_philo *philo, char *str)
{
	if (pthread_mutex_lock(&program->mx_write))
		return (set_philo_error(philo), 1);
	if (program->philos_end)
		philo->err = 1;
	if (print_action__now(program, philo->index, str) == -1)
		return (exit_(philo, CLEAN__MX_PUT));
	pthread_mutex_unlock(&program->mx_write);
	return (0);
}
