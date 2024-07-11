/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:23:11 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/11 00:52:45 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

inline int	print_action(unsigned long time, int index, char *str)
{
	return (printf("%ld %d %s\n", time, index, str));
}

static inline int	print_action__now(t_program *program, int index, char *str)
{
	return (print_action((get_time() - program->time_start) * 0.001, index, str));
}

int	philo__write(t_program *program, t_philo *philo, char *str)
{
	return ((\
		pthread_mutex_lock(&program->mx_write) && exit_(philo, CLEAN__NONE)) || \
		(program->philos_end && (philo->err = 1) == 1) || \
		(print_action__now(program, philo->index, str) == -1 && exit_(philo, CLEAN__MX_PUT)) || \
		pthread_mutex_unlock(&program->mx_write));
}
