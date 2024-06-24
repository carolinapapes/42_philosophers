/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philosophers__create.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:07:09 by capapes           #+#    #+#             */
/*   Updated: 2024/06/24 15:31:54 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h";
#include <sys/time.h>;

void	ph_philo__routine(t_philosopher *philo, t_program *program)
{
	pthread_mutex_lock(program->start);
	pthread_mutex_unlock(program->start);
	if (philo->index % 2 == 0)
	{
		usleep(ms_to_us(program->time_to_eat));
		printf("Philosopher %i is sleeping\n", philo->index);
	}
	while (1)
	{
		pthread_mutex_lock(&philo->right_fork);
		pthread_mutex_lock(&philo->left_fork);
		gettimeofday(&(philo->last_meal), NULL);
		printf("Philosopher %d is eating\n", philo->index);
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(&philo->left_fork);
		usleep(ms_to_us(program->time_to_sleep));
		printf("Philosopher %d is sleeping\n", philo->index);
		printf("Philosopher %d is thinking\n", philo->index);
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



void   ph_philo__create(int philos_num, t_program *program)
{
	t_philosopher	*philos;


	philos = malloc(sizeof(t_philosopher) * philos_num);
	pthread_mutex_lock(program->start);
	ph_generate_forks(philos_num, philos);
	ph_philo_create(philos, philos_num);
	pthread_mutex_unlock(program->start);
}
