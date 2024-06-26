/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philosophers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:51:17 by capapes           #+#    #+#             */
/*   Updated: 2024/06/26 16:53:25 by capapes          ###   ########.fr       */
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
	unsigned long int	last_meal;
	t_program		*program;

}	t_philosopher;

typedef struct s_program
{
	unsigned long int	n_philosophers;
	unsigned long int	n_meals;
	unsigned long int	time_to_die;
	unsigned long int	time_to_eat;
	unsigned long int	time_to_sleep;
	pthread_mutex_t	write;
	pthread_mutex_t	start;
	struct timeval	start_time;
	int				is_dead;
	unsigned long int	start_time_u;
}	t_program;

#endif