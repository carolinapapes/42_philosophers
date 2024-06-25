/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philosophers__create.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:07:09 by capapes           #+#    #+#             */
/*   Updated: 2024/06/25 18:57:48 by capapes          ###   ########.fr       */
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

void	ph_philo__write(t_philosopher *philo, t_program *program, char *str, int isDead)
{
	unsigned int	time_now;
	pthread_mutex_lock(&program->write);
	ph_get_timeof_day_ms(&time_now);
	printf("%u %d %s\n", time_now - program->start_time_u, philo->index, str);
	pthread_mutex_unlock(&program->write);
}

void	ph_philo__sleep(t_philosopher *philo, t_program *program)
{
	ph_philo__write(philo, program, "is sleeping", 0);
	usleep(ms_to_us(program->time_to_sleep));
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

void	ph_philo__eat(t_philosopher *philo, t_program *program)
{
	philo->last_meal = get_time_ms();
	ph_philo__write(philo, program, "is eating", 0);
	usleep(ms_to_us(program->time_to_eat));
}

void	ph_philo__get_forks(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	pthread_mutex_lock(&philo->left_fork);
}

void	ph_philo__drop_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

void	ph_philo__prethink(t_philosopher *philo, t_program *program)
{
	if (philo->index % 2 == 0)
	{
		ph_philo__think(philo, program);
		usleep(ms_to_us(program->time_to_eat - 1));
	}
}

void	ph_simulation__start(t_program *program)
{
	pthread_mutex_lock(program->start);
	pthread_mutex_unlock(program->start);
}

void	ph_philo__think(t_philosopher *philo, t_program *program)
{
	ph_philo__write(philo, program, "is thinking", 0);
}

void	ph_philo__routine(t_philosopher *philo, t_program *program)
{
	ph_simulation__start(program);
	ph_philo__prethink(philo, program);
	while (1)
	{
		ph_philo__get_forks(philo);
		
		ph_philo__eat(philo, program);
		ph_philo__drop_forks(philo);
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

void	ph_philo_create(t_philosopher *philos, int philos_num)
{
	int				i;

	i = -1;
	while (++i < philos_num)
		pthread_create(&philos[i].id, NULL, ph_philo__routine, &philos[i]);
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
