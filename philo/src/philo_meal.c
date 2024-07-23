/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_meal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:59:59 by capapes           #+#    #+#             */
/*   Updated: 2024/07/23 01:00:54 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo.h"
#include "philo_helpers.h"
#include <unistd.h>

static int	next(t_philo *philo, t_program *program)
{
	philo->meal_n++;
	philo->meal_t = get_time() - program->time_start;
	return (philo->meal_t < 0);
}

inline int	philo_meal(t_philo *philo, t_program *program)
{
	return (
		philo_mx_lock(philo, &program->mx_write, PHILO_ERRR)
		|| (check_philo_end(program, philo)
			|| next(philo, program)
			|| action(philo->meal_t * 0.001, philo->index, EAT))
		| philo_mx_unlock(philo, &program->mx_write, PHILO_ERR_WRITE)
		|| philo_usleep(philo, program->time_to_eat, PHILO_ERRR));
}
