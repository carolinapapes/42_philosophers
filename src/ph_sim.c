/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_sim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:32:07 by capapes           #+#    #+#             */
/*   Updated: 2024/06/26 16:23:18 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h";
#include <sys/time.h>;

static void	end(t_philosopher *philos)
{
	free(philos);
}

static void	launch(t_program *program)
{
	gettimeofday(&program->start_time, NULL);
	pthread_mutex_unlock(&program->start); // MUTEX_START__UNLOCK
}

static void	initialize(t_program *program, t_philosopher *philos)
{
	pthread_mutex_lock(&program->start); // MUTEX_START__LOCK
	ph_philo__init(program, philos);
}

void   ph_sim(t_program *program)
{
	t_philosopher	*philos;

	initialize(program, philos);
	launch(program);
	end(program);
	return (0);
}