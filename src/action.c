/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:23:11 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/20 15:25:44 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include "philo_helpers.h"
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
	return (printf("%ld %d %s\n", time, index, str) == -1);
}

static int	now(t_program *program, t_philo *philo, char *str, int err)
{
	long	time;

	time = (get_time() - program->time_start) * 0.001;
	return ((\
			program->philos_end || philo->err || time < 0 || \
			action(time, philo->index, str)) \
			&& philo_exit(philo, err));
}

inline int	action_now(t_program *program, t_philo *philo, char *str, int err)
{
	return (
		philo_mx_lock(philo, &program->mx_write, err) || \
		now(program, philo, str, err | PHILO_ERR_WRITE) || \
		philo_mx_unlock(philo, &program->mx_write, err | PHILO_ERR_WRITE) \
		);
}
