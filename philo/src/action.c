/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:23:11 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/22 19:45:57 by capapes          ###   ########.fr       */
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

inline int	action(unsigned long time, int index, char *str)
{
	return (printf("%ld %d  %s\n", time, index, str) == -1);
}

static int	now(t_program *program, t_philo *philo, char *str)
{
	long	time;

	time = (get_time() - program->time_start) * 0.001;
	return ((
			program->philos_end || philo->err || time < 0
			|| action(time, philo->index, str))
		&& philo_exit(philo, PHILO_ERR_WRITE));
}

inline int	action_now(t_program *program, t_philo *philo, char *str, int err)
{
	return ((
			philo_mx_lock(philo, &program->mx_write, err)
			|| now(program, philo, str)
			|| philo_mx_unlock(philo, &program->mx_write, PHILO_ERR_WRITE))
		&& philo_exit(philo, err));
}
