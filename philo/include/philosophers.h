/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 08:41:23 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/22 19:17:11 by capapes          ###   ########.fr       */
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
# define MX_PHILO 18
# define MX_FULL 31

// CLEAN = cleanup identifiers - see program_exit
# define CLEAN_PROGRAM_MX 1
# define CLEAN_FREE 3
# define CLEAN_PHILOS 7
# define CLEAN_FULL 15
# define CLEAN_START 32
# define CLEAN_START_PHILOS 33

# define STR_INT_MAX "2147483647"

// ERRORS
# define ERR_ARGS_QTY "Philosophers: wrong number of arguments\n"
# define ERR_ARGS_INT "Philosophers: wrong argument type\n"
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
	int					philos_end;
	int					rutine;
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
	int							meal_n;
	long int					meal_t;
	pthread_mutex_t				*mx_fork_l;
	pthread_mutex_t				mx_fork_r;
	t_program					*program;
};

int					put_err(char *str);
int					parser(int argc, char *argv[]);

// INIT SECTION
int					philo_init(t_program *program, int i);
int					philo_meal(t_philo *philo, t_program *program);
void				philo_rutine(t_philo *philo);
int					philo_usleep(t_philo *philo, int time, int err);
int					philo_mx_lock(t_philo *philo, \
						pthread_mutex_t *mutex, int err);

int					philos_init(t_program *program);
int					philos_th_join(t_program *program, int i);
int					philos_mx_destroy(t_program *program, int i);

// UTILS SECTION
long int			get_time(void);
int					ft_puterr(const char *s);

// PROGRAM SECTION
int					program_init(char **argv, t_program *program);
int					program_exit(t_program *program, int n, int i, int status);
int					program_run(t_program *program);
int					program_start(t_program *program, int err);
int					program_status(t_program *program, t_philo *philo, \
						long int time, int *k);

// PROGRAM SYSTEM UTILS
int					program_mx_destroy(t_program *program, int i);
int					program_mx_init(t_program *program, \
						pthread_mutex_t *mutex, int err);
int					program_mx_lock(t_program *program, \
						pthread_mutex_t *mutex, int err);

int					is_not_int(char **s);

int					ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					check_philo_end(t_program *program, \
						t_philo *philo, int err);
int					action(unsigned long time, int index, char *str);
int					action_now(t_program *program, \
						t_philo *philo, char *str, int err);
int					forks_get(t_philo *philo, t_program *program);
int					forks_drop(t_philo *philo);
int					philo_check_death(t_program *program, t_philo *philo);

#endif