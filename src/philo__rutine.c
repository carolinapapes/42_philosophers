/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo__rutine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:56:07 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/04 19:33:18 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

static void	philo__sleep(t_program *program, int *i, int index)
{
	philo__write(program, i, index, "is sleeping");
	if (*i)
		usleep(program->time_to_sleep);
}

static void	think(t_program *program, int *i, int index)
{
	philo__write(program, i, index, "is thinking");
}

static void	trigger_run(t_program *program, int index)
{
	pthread_mutex_lock(&program->mx_start);
	pthread_mutex_unlock(&program->mx_start);
	if (!(index & 1))
		usleep(program->time_to_eat - 100);
}

void	philo__rutine(t_philo *philo)
{
	t_program	*program;
	int			index;
	int			i;
	int			*c;

	i = 1;
	c = &i;
	index = philo->index;
	program = philo->program;
	trigger_run(program, index);
	while (i)
	{
		philo__eat(philo, c, program, index);
		philo__sleep(program, c, index);
		think(program, c, index);
	}
}
