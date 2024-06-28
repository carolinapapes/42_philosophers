/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:52:12 by capapes           #+#    #+#             */
/*   Updated: 2024/06/28 17:18:35 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <sys/time.h>
#include <stdlib.h>


static void	mxcreate(t_philosopher *philos, int i, t_program *program)
{
	pthread_mutex_init(&philos[i].right_fork, NULL);  // FORK RIGHT INITIALIZATION
	if (i != 0)	
		philos[i - 1].left_fork = &philos[i].right_fork;
	else
		philos[program->n_philosophers - 1].left_fork = &philos[0].right_fork;
}

static inline int thcreate(t_philosopher *philo)
{
	return (pthread_create(philo->id, NULL, (void *)ph_philo__routine, philo));
}

static void initialize(t_philosopher *philo, t_program *program)
{
	philo->meals = 0;
	philo->last_meal = 0;
	philo->index = -1;
	philo->id = NULL;
	philo->left_fork = NULL;
	philo->program = program;
}

void	ph_philo__init(t_philosopher *philos, t_program *program)
{
	int	i;

	philos = malloc(sizeof(t_philosopher) * program->n_philosophers); // needs cleaning
	i = -1;
	while (++i < program->n_philosophers)
	{
		initialize(&philos[i], program);
        mxcreate(philos, i, program);
		
	}
	i = -1;
	while (++i < program->n_philosophers)
	{
		thcreate(&philos[i]);
	}
}