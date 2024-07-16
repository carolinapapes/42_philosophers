/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helpers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:05:01 by capapes           #+#    #+#             */
/*   Updated: 2024/07/16 16:31:21 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_HELPERS_H
# define PHILO_HELPERS_H

# include "philo.h"
# include "philosophers.h"

int	philos__iter(t_program *program, int n, int (*f)(t_program *, int));
int	philo__mx_lock(t_philo *philo, pthread_mutex_t *mutex, int err);
int	philo__mx_unlock(t_philo *philo, pthread_mutex_t *mutex, int err);
int	philo__mx_init(t_philo *philo, pthread_mutex_t *mutex, int err);
int	philo__mx_destroy(t_philo *philo, pthread_mutex_t *mutex, int err);
int	philo__usleep(t_philo *philo, int time, int err);
int	exit_(t_philo *philo, int err);

#endif