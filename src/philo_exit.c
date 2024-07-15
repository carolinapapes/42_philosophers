/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:58:54 by capapes           #+#    #+#             */
/*   Updated: 2024/07/13 11:26:35 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo.h"
#include "philo_helpers.h"

void	_set_error(t_philo *philo)
{
	int	unlock;

	unlock = 1;
	if (pthread_mutex_lock(&philo->mx_meal))
		unlock = 0;
	philo->err = 1;
	if (unlock)
		pthread_mutex_unlock(&philo->mx_meal);
}

inline int	check_philo_end(t_program *program, t_philo *philo, int err)
{
	return (program->philos_end \
		&& (*(&(philo->err)) = 1) == 1 \
		&& exit_(philo, err));
}

int	exit_(t_philo *philo, int err)
{
	_set_error(philo);
	err & PHILO_ERR_FORK_R && pthread_mutex_unlock(&philo->mx_fork_r);
	err & PHILO_ERR_FORK_L && pthread_mutex_unlock(philo->mx_fork_l);
	err & PHILO_ERR_MEAL && pthread_mutex_unlock(&philo->mx_meal);
	err & PHILO_ERR_WRITE && pthread_mutex_unlock(&philo->program->mx_write);
	err & PHILO_ERR_START && pthread_mutex_unlock(&philo->program->mx_start);
	err & PHILO_ERR_MEAL_INIT && pthread_mutex_destroy(&philo->mx_meal);
	err & PHILO_ERR_FORK_R_INIT && pthread_mutex_destroy(&philo->mx_fork_r);
	return (1);
}
