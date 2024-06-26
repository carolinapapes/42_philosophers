/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philosophers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:51:17 by capapes           #+#    #+#             */
/*   Updated: 2024/06/25 19:54:39 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_PHILOSOPHERS_H
# define PH_PHILOSOPHERS_H

# include <pthread.h>
# include <sys/time.h>

int	ft_are_str_int(int argc, char *argv[]);

typedef struct s_philosopher
{
	pthread_t		*id;
	int				index;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				meals;
	unsigned int	last_meal;

}	t_philosopher;

typedef struct s_program
{
	unsigned int	n_philosophers;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	n_meals;
	pthread_mutex_t	write;
	t_philosopher	*t_philo_list;
	pthread_mutex_t	*start;
	struct timeval	start_time;
	unsigned int	start_time_u;
	int				is_dead;
}	t_program;

#endif