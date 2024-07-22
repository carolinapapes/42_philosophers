/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helpers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:05:01 by capapes           #+#    #+#             */
/*   Updated: 2024/07/22 21:11:35 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_HELPERS_H
# define PHILO_HELPERS_H

# include "philo.h"
# include "philosophers.h"

int	philos_iter(t_program *program, int n, int (*f)(t_program *, int));
int	philo_mx_lock(t_philo *philo, pthread_mutex_t *mutex, int err);
int	philo_mx_unlock(t_philo *philo, pthread_mutex_t *mutex, int err);
int	philo_mx_init(t_philo *philo, pthread_mutex_t *mutex, int err);
int	philo_usleep(t_philo *philo, int time, int err);
int	philo_exit_print(t_philo *philo, int err);
int	philo_exit(t_philo *philo, int err);

#endif