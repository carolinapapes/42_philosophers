/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philosophers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:51:17 by capapes           #+#    #+#             */
/*   Updated: 2024/06/22 19:21:36 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>

int	ft_are_str_int(int argc, char *argv[]);

typedef struct s_philosopher
{
    pthread_t           *id;
    pthread_mutex_t     *left_fork;
    pthread_mutex_t     *right_fork;
    int                 meals;
    int                 last_meal;
} t_philosopher;

typedef struct s_program
{
    int                 n_philosophers;
    int                 time_to_die;
    int                 time_to_eat;
    int                 time_to_sleep;
    int                 n_meals;
    t_philosopher       *t_philo_list;
} t_program;

#endif