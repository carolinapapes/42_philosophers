/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:52:12 by capapes           #+#    #+#             */
/*   Updated: 2024/06/30 22:06:45 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"

static void	mxcreate(t_philosopher *philos, int i, t_program *program)
{
	if (pthread_mutex_init(&philos[i].right_fork, NULL))
		exit(1);
	if (i != 0)
		philos[i].left_fork = &philos[i - 1].right_fork;
	if (i == program->n_philosophers - 1 && program->n_philosophers > 1)
		philos[0].left_fork = &philos[i].right_fork;
}

static inline int	thcreate(t_philosopher *philo)
{
	return (pthread_create(&philo->id, NULL, (void *)ph_philo__routine, philo));
	// should return if failed
}

void	ph_philo__init(t_program *program)
{
	int	i;

	program->philos = malloc(sizeof(t_philosopher) * program->n_philosophers);
	// should return if failed to allocate memory
	i = -1;
	while (++i < program->n_philosophers)
	{
		ft_pointer_memset(&program->philos[i], sizeof(t_philosopher));
		// should return and clean if failed to set memory || maybe remove from while loop
		program->philos[i].program = program;
		program->philos[i].index = i;
		program->philos[i].meals = 0; // should be already zero
		program->philos[i].last_meal = 0; // should be already zero
		mxcreate(program->philos, i, program);
		// should return and clean if failed to create mutex
	}
	i = -1;
	while (++i < program->n_philosophers)
		thcreate(&program->philos[i]);
		// should return and clean if failed to create thread
}
