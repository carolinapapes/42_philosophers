/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:37:31 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/16 16:31:21 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo.h"
#include "philo_helpers.h"
#include <unistd.h>

inline int	philo_mx_lock(t_philo *philo, pthread_mutex_t *mutex, int err)
{
	return (pthread_mutex_lock(mutex) && philo_exit(philo, err));
}

inline int	philo_mx_unlock(t_philo *philo, pthread_mutex_t *mutex, int err)
{
	return (pthread_mutex_unlock(mutex) && philo_exit(philo, err));
}

inline int	philo_mx_init(t_philo *philo, pthread_mutex_t *mutex, int err)
{
	return (pthread_mutex_init(mutex, NULL) && philo_exit(philo, err));
}

inline int	philo_usleep(t_philo *philo, int time, int err)
{
	return (philo->err || (usleep(time) && philo_exit(philo, err)));
}
