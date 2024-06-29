/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:52:12 by capapes           #+#    #+#             */
/*   Updated: 2024/06/29 23:29:53 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>

static void	mxcreate(t_philosopher *philos, int i, t_program *program)
{
	if(pthread_mutex_init(&philos[i].right_fork, NULL))  // FORK RIGHT INITIALIZATION
		exit(1);
	if (i != 0)	
		philos[i].left_fork = &philos[i - 1].right_fork;
	if (i == program->n_philosophers - 1)
		philos[0].left_fork = &philos[i].right_fork;
}

static inline int thcreate(t_philosopher *philo)
{
	return (pthread_create(&philo->id, NULL, (void *)ph_philo__routine, philo));
}

// static void initialize(t_philosopher *philo, t_program *program, int i)
// {
// 	philo->meals = 0;
// 	philo->last_meal = 0;
// 	philo->index = i;
// 	philo->id = 0;
// 	philo->left_fork = NULL;
// 	philo->program = program;
// }


inline static void  initialize(void *p, size_t n)
{
	memset(p, 0, n);
}




void	ph_philo__init(t_program *program)
{
	int	i;

	program->philos = malloc(sizeof(t_philosopher) * program->n_philosophers); // needs cleaning
	i = -1;
	while (++i < program->n_philosophers)
	{
		initialize(&program->philos[i], sizeof(t_philosopher));
		program->philos[i].program = program;
		program->philos[i].index = i;
		program->philos[i].meals = 0;
		program->philos[i].last_meal = 0;
        mxcreate(program->philos, i, program);
	}
	i = -1;
	while (++i < program->n_philosophers)
		thcreate(&program->philos[i]);
}



