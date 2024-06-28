/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_sim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:32:07 by capapes           #+#    #+#             */
/*   Updated: 2024/06/28 17:17:51 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <sys/time.h>

static void end(t_program *program, t_philosopher *philos)
{
	int i;

	i = -1;
	while(++i < program->n_philosophers)
		pthread_join(*philos[i].id, NULL); // JOIN_THREADS
}

static void	launch(t_program *program)
{
	gettimeofday(&program->start_time, NULL);
	pthread_mutex_unlock(&program->start); // MUTEX_START__UNLOCK
}

static void	initialize(t_program *program, t_philosopher *philos)
{
	pthread_mutex_init(&program->start, NULL); 
	pthread_mutex_init(&program->write, NULL);
	pthread_mutex_lock(&program->start); // MUTEX_START__LOCK
	ph_philo__init(philos, program);
}

void   ph_sim(t_program *program)
{
	t_philosopher	*philos;

	philos = NULL;
	initialize(program, philos);
	launch(program);
	end(program, philos);
	return ;
}