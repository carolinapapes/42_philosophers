/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:23:11 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/23 01:13:24 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo_helpers.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

long int	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (-1);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

static inline long int	get_now(t_program *program)
{
	return ((get_time() - program->time_start) * 0.001);
}

inline int	action(unsigned long time, int index, char *str)
{
	return (time < 0 || printf("%ld %d  %s\n", time, index, str) == -1);
}

static int	now(t_program *program, t_philo *philo, char *str)
{
	return ((
			program->philos_end
			|| philo->err
			|| action(get_now(program), philo->index, str)));
}

inline int	print_now(t_program *program, t_philo *philo, char *str, int err)
{
	return ((
			philo_mx_lock(philo, &program->mx_write, err)
			|| now(program, philo, str)
			| philo_mx_unlock(philo, &program->mx_write, PHILO_ERR_WRITE))
		&& philo_exit(philo, err));
}
