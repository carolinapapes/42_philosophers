/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos__utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:37:31 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/07 00:09:12 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

int	philos__iter(t_program *program, int n, int (*f)(t_program *, int))
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < n && !j)
		j = f(program, i);
	return (j);
}

void	set_philo_error(t_philo *philo)
{
	int	unlock;

	unlock = 1;
	if (pthread_mutex_lock(&philo->mx_meal))
		unlock = 0;
	philo->err = 1;
	if (unlock)
		pthread_mutex_unlock(&philo->mx_meal);
}

int	exit_err(t_philo *philo, int err)
{
	set_philo_error(philo);
	err & CLEAN__FORK_R && pthread_mutex_unlock(&philo->mx_fork_r);
	err & CLEAN__FORK_L && pthread_mutex_unlock(philo->mx_fork_l);
	err & CLEAN__MX_SET && pthread_mutex_unlock(&philo->mx_meal);
	err & CLEAN__MX_PUT && pthread_mutex_unlock(&philo->program->mx_write);
	return (1);
}
