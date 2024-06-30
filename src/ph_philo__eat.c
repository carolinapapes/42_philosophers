/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:33:38 by carolinapap       #+#    #+#             */
/*   Updated: 2024/06/30 03:27:27 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <sys/time.h>

static void	fork__get(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	ph_philo__write(philo, "Takes right fork");
	pthread_mutex_lock(philo->left_fork);
	ph_philo__write(philo, "Takes left fork");
}

static void	fork__drop(t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

static void	meal__get(t_philosopher *philo)
{
	ph_philo__write(philo, "Is eating");
	ph_get_timeof_day_u(&philo->last_meal);
	usleep(philo->program->time_to_eat);
}

static inline void	meal__add(t_philosopher *philo)
{
	philo->meals++;
}

void	ph_philo__eat(t_philosopher *philo)
{
	fork__get(philo);
	meal__get(philo);
	meal__add(philo);
	fork__drop(philo);
}
