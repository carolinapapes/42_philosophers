/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philosophers__create.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:07:09 by capapes           #+#    #+#             */
/*   Updated: 2024/06/26 01:56:00 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h";
#include <sys/time.h>;


void ph_get_timeof_day_ms(unsigned int *time_ms)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	*time_ms = get_time_ms(now);
}

ph_philo_am_I_dead(t_philosopher *philo, t_program *program)
{
	unsigned int	time_now;
	unsigned int	time_diff;

	ph_get_timeof_day_ms(&time_now); // needs checks
	time_diff = time_now - philo->last_meal;
	if (time_diff > program->time_to_die)
	{
		ph_philo__write(philo, program, "is dead", 1);
		pthread_mutex_lock(&philo->right_fork);
		pthread_mutex_lock(&philo->left_fork);
		exit(1);
	}
}

void	ph_simulation__start(t_program *program)
{
	pthread_mutex_lock(program->start);
	pthread_mutex_unlock(program->start);
}

void   ph_philo__check_death(t_philosopher *philo, t_program *program)
{
	if (program->is_dead)
		return ;
	ph_philo_am_I_dead(philo, program);
}

void	ph_philo__routine(t_philosopher *philo, t_program *program)
{
	ph_philo__prethink(philo, program);
	while (1)
	{
		ph_philo__eat(philo, program);
		ph_philo__sleep(philo, program);
		ph_philo__think(philo, program);
	}
}
void	ph_philo_assign_left_fork(t_philosopher *philos, int philos_num, int i)
{
	if (i = 0)
		philos[philos_num - 1].left_fork = philos[0].right_fork;
	else
		philos[i - 1].left_fork = philos[i].right_fork;
}


void	ph_create_fork(t_philosopher *philos, int philos_num, int i)
{

	pthread_mutex_init(&philos[i].right_fork, NULL); 
	ph_philo_assign_left_fork(philos, philos_num, i);
}

void	ph_generate_forks(int philos_num, t_philosopher *philos)
{
	int	i;

	i = -1;
	while (++i < philos_num)
		ph_create_fork(philos, philos_num, i);
}

inline int create(t_philosopher *philos, int i)
{
	return (pthread_create(&philos[i].id, NULL, ph_philo__routine, &philos[i]));
}

void	ph_philo_create(t_philosopher *philos, t_program *program)
{
	int				i;
	int				j;

	i = -1;
	while (++i < program->n_philosophers)
		if (create(philos) == -1)
		{
			program->is_dead = 1;
		}
	
}

void   ph_sim__init(t_program *program)
{
	t_philosopher	*philos;

	philos = malloc(sizeof(t_philosopher) * program->n_philosophers);
	pthread_mutex_lock(program->start);
	ph_generate_forks(program->n_philosophers, philos);
	ph_philo_create(philos, program->n_philosophers);
	gettimeofday(&program->start_time, NULL);
	pthread_mutex_unlock(program->start);
	free(philos);
	return (0);
}
