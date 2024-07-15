/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 08:41:23 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/12 17:43:49 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define START_WITHOUT_ERR 0

// MX = mutex identifiers
# define MX_NONE 0
# define MX_START 1
# define MX_END 2
# define MX_WRITE 4
# define MX_PROGRAM 7
# define MX_FORK 8
# define MX_MEAL 10
# define MX_PHILO 18
# define MX_FULL 31

// CLEAN = cleanup identifiers - see program__exit
# define CLEAN_PROGRAM 1
# define CLEAN_FREE 3
# define CLEAN_PHILOS 7
# define CLEAN_FULL 15
# define CLEAN_START 31

# define STR_INT_MAX "2147483647"


// ERRORS
# define ERR_MALLOC "Philosophers: malloc error\n"
# define ERR_ARGS "Philosophers: wrong arguments\n"
# define ERR_MUTEX "Philosophers: mutex error\n"
# define ERR_THREAD "Philosophers: thread error\n"
# define ERR_INIT_FAIL 1
// TYPES
typedef struct s_philosopher	t_philo;

typedef struct s_program
{
	int					meals_n;
	pthread_mutex_t		mx_end;
	pthread_mutex_t		mx_start;
	pthread_mutex_t		mx_write;
	t_philo				*philos;
	volatile int		philos_end;
	int					philos_n;
	long int			time_to_die;
	long int			time_to_eat;
	long int			time_to_sleep;
	long int			time_start;
}	t_program;

struct s_philosopher
{
	pthread_t					id;
	int							index;
	int							err;
	volatile int				meal_n;
	volatile long int			meal_t;
	pthread_mutex_t				*mx_fork_l;
	pthread_mutex_t				mx_fork_r;
	pthread_mutex_t				mx_meal;
	t_program					*program;
};

// INIT SECTION
int					philo__init(t_program *program, int i);
int					philos__init(t_program *program);
int					program__init(char **argv, t_program *program);
void				philo__rutine(t_philo *philo);
int					ph_parser(int argc, char *argv[]);

// UTILS SECTION
int					program__mx_destroy(t_program *program, int i);
long int			get_time(void);
int					ft_puterr(const char *s);

// CLEAUP
int					philos__mx_destroy(t_program *program, int i);
int					philos__th_join(t_program *program, int i);
int					philo__meal(t_philo *philo, t_program *program);

// DEBUGGER
void				philo__print(t_philo *philo);
void				program__print(t_program *program);
void				program__mx_print(t_program *program, \
					void (*f)(t_program *program));
void				philo__mx_print(t_philo *philo, void (*f)(t_philo *philo));
void				program__print_end(int j, t_program *program, t_philo *philo);

int					program__start(t_program *program, int err);
int					program__status(t_program *program);

int					program__exit(t_program *program, int n, int i, int status); 
int					mx__meals(t_program *program, t_philo *philo, \
					long int time, int *k);
int					philo__usleep(t_philo *philo, int time, int err);
int					mx_lock(t_philo *philo, pthread_mutex_t *mutex, int err);

int					ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ph_parser(int argc, char *argv[]);
int					check_philo_end(t_program *program, t_philo *philo, int err);
int					action(unsigned long time, int index, char *str);
int					action__now(t_program *program, t_philo *philo, char *str, int err);
void				philo__actions(t_program *program, t_philo *philo);
int					forks__get(t_philo *philo, t_program *program);
int					forks__drop(t_philo *philo);
#endif