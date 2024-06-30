/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philosophers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:51:17 by capapes           #+#    #+#             */
/*   Updated: 2024/06/30 15:27:30 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_PHILOSOPHERS_H
# define PH_PHILOSOPHERS_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include "ph_utils.h"
# include <stdio.h>

# include <stddef.h>

# define STR_INT_MAX "2147483647"
# define STR_INT_MIN "2147483648"

int	ft_isempty(char *s);
int	ft_issign(int c);
int	ft_isdigit(int c);
int	ft_strlen(char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);

typedef struct s_philosopher	t_philosopher;

typedef struct s_program
{
	int					n_philosophers;
	int					n_meals;
	int					is_dead;
	unsigned long int	time_to_die;
	unsigned long int	time_to_eat;
	unsigned long int	time_to_sleep;
	pthread_mutex_t		write;
	pthread_mutex_t		start;
	unsigned long int	start_time_u;
	t_philosopher		*philos;
}	t_program;

struct s_philosopher
{
	pthread_t			id;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		right_fork;
	int					index;
	int					meals;
	unsigned long int	last_meal;
	t_program			*program;

};

void						ph_philo__eat(t_philosopher *philo);
void						ph_philo__init(t_program *program);
void						ph_philo__routine(t_philosopher *philo);
void						ph_philo__sleep(t_philosopher *philo);
void						ph_philo__think(t_philosopher *philo);
void						ph_philo__write(t_philosopher *philo, char *str);
void						ph_philo__prethink(t_philosopher *philo);
void						ph_philos__deaths(t_program *program);
void						ph_sim(t_program *program);
void						ph_get_timeof_day_u(unsigned long int *time_u);
// void						print_philos(t_philosopher *philos, t_program *program);
// void						print_philo(t_philosopher *philo);
inline unsigned long int	time_diff_u(unsigned long int t1, \
								unsigned long int t2);
void 						ph_philos__meals(t_program *program);

#endif