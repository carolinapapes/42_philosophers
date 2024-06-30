/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philosophers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:51:17 by capapes           #+#    #+#             */
/*   Updated: 2024/06/30 21:56:44 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_PHILOSOPHERS_H
# define PH_PHILOSOPHERS_H

# include <pthread.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

# define STR_INT_MAX "2147483647"

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

int						ft_isempty(char *s);
int						ft_strlen(char *s);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
int						ft_are_str_int(int argc, char *argv[]);
void					ph_philo__eat(t_philosopher *philo);
void					ph_philo__init(t_program *program);
void					ph_philo__routine(t_philosopher *philo);
void					ph_philo__sleep(t_philosopher *philo);
void					ph_philo__think(t_philosopher *philo);
void					ph_philo__write(t_philosopher *philo, char *str);
void					ph_philo__prethink(t_philosopher *philo);
void					ph_philos__deaths(t_program *program);
void					ph_sim(t_program *program);
void					ph_get_timeof_day_u(unsigned long int *time_u);
int						ph_parser(t_program *program, int argc, char *argv[]);

#endif