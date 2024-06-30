/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_sim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:32:07 by capapes           #+#    #+#             */
/*   Updated: 2024/06/30 22:06:59 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"

static void	free_philos(t_program *program)
{
	int	i;

	i = -1;
	while (++i < program->n_philosophers)
		pthread_mutex_destroy(&program->philos[i].right_fork);
	free(program->philos);
}

static void	end(t_program *program)
{
	int	i;

	ph_philos__deaths(program);
	i = -1;
	while (++i < program->n_philosophers)
		pthread_join(program->philos[i].id, NULL);
		// should return if failed
	free_philos(program);
}

static void	launch(t_program *program)
{
	ph_get_timeof_day_u(&program->start_time_u);
	pthread_mutex_unlock(&program->start);
	// should return if failed
	pthread_mutex_destroy(&program->start);
	// should return if failed
}

static void	initialize(t_program *program)
{
	pthread_mutex_init(&program->start, NULL);
	// should return if failed
	pthread_mutex_init(&program->write, NULL);
	// should return if failed
	pthread_mutex_lock(&program->start);
	// should return if failed
	ph_philo__init(program);
}

void	ph_sim(t_program *program)
{
	initialize(program);
	launch(program);
	end(program);
	return ;
}
