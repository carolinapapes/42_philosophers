/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo__rutine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:56:07 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/03 12:42:45 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

unsigned long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec * 0.001);
}

void	mx__write(t_program *program, int i, char *str)
{
	pthread_mutex_lock(&program->mx_write);
	printf("%lu\t%d\t%s\n", get_time(), i, str);
	pthread_mutex_unlock(&program->mx_write);
}

static void	eat(t_philo *philo, int *i)
{
	pthread_mutex_lock(&philo->mx_fork_r);
	mx__write(philo->program, philo->index, "has taken a fork");
	pthread_mutex_lock(philo->mx_fork_l);
	mx__write(philo->program, philo->index, "has taken a fork");
	pthread_mutex_lock(&philo->mx_meal);
	pthread_mutex_lock(&philo->program->mx_write);
	if (!philo->program->philos_end)
	{
		philo->meal_t = get_time();
		philo->meal_n++;
		printf("%ld %d is eating\n", get_time() - \
			philo->program->time_start, philo->index);
	}
	else
	{
		*i = 0;
		pthread_mutex_unlock(&philo->program->mx_write);
		pthread_mutex_unlock(&philo->mx_meal);
		return ;
	}
	pthread_mutex_unlock(&philo->program->mx_write);
	pthread_mutex_unlock(&philo->mx_meal);
	usleep(philo->program->time_to_eat);
	pthread_mutex_unlock(&philo->mx_fork_r);
	pthread_mutex_unlock(philo->mx_fork_l);
}

static void	philo__sleep(t_philo *philo, int *i)
{
	pthread_mutex_lock(&philo->program->mx_write);
	if (philo->program->philos_end)
	{
		pthread_mutex_unlock(&philo->program->mx_write);
		*i = 0;
		return ;
	}
	printf("%ld %d is sleeping\n", get_time() - \
		philo->program->time_start, philo->index);
	pthread_mutex_unlock(&philo->program->mx_write);
	usleep(philo->program->time_to_sleep);
}

void	think(t_philo *philo, int *i)
{
	pthread_mutex_lock(&philo->program->mx_write);
	if (philo->program->philos_end)
	{
		pthread_mutex_unlock(&philo->program->mx_write);
		*i = 0;
		return ;
	}
	printf("%ld %d is thinking\n", get_time() - philo->program->time_start, philo->index);
	pthread_mutex_unlock(&philo->program->mx_write);
}

void	philo__rutine(t_philo *philo)
{
	pthread_mutex_lock(&philo->program->mx_start);
	pthread_mutex_unlock(&philo->program->mx_start);
	
	int	i;

	if ((philo->index & 1) == 0)
		usleep(philo->program->time_to_eat - 100);
	i = 1;
	while (i)
	{
		eat(philo, &i);
		if (!i)
			break ;
		philo__sleep(philo, &i);
		think(philo, &i);
	}
}
