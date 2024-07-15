/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos__utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:37:31 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/13 11:28:30 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo.h"
#include "philo_helpers.h"
#include <unistd.h>

inline int	mx_lock(t_philo *philo, pthread_mutex_t *mutex, int err)
{
	return (pthread_mutex_lock(mutex) && exit_(philo, err));
}

inline int	mx_unlock(t_philo *philo, pthread_mutex_t *mutex, int err)
{
	return (pthread_mutex_unlock(mutex) && exit_(philo, err));
}

inline int	philo__mx_init(t_philo *philo, pthread_mutex_t *mutex, int err)
{
	return (pthread_mutex_init(mutex, NULL) && exit_(philo, err));
}

inline int	philo__mx_destroy(t_philo *philo, pthread_mutex_t *mutex, int err)
{
	return (pthread_mutex_destroy(mutex) && exit_(philo, err));
}

inline int	philo__usleep(t_philo *philo, int time, int err)
{
	return (philo->err || (usleep(time) && exit_(philo, err)));
}
