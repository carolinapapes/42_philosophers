/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 08:41:23 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/02 09:10:00 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>

typedef struct s_philosopher	t_philosopher;

typedef struct s_program
{
	int					meals_n;
	pthread_mutex_t		mx_end;
	pthread_mutex_t		mx_start;
	pthread_mutex_t		mx_write;
	t_philosopher		*philos;
	volatile int		philos_end;
	int					philos_n;
	unsigned long int	time_to_die;
	unsigned long int	time_to_eat;
	unsigned long int	time_to_sleep;
}	t_program;

struct s_philosopher
{
	pthread_t					id;
	int							index;
	volatile int				meal_n;
	volatile unsigned long int	mals_t;
	pthread_mutex_t				*mx_fork_l;
	pthread_mutex_t				mx_fork_r;
	pthread_mutex_t				mx_meal;
	t_program					*program;

};

#endif