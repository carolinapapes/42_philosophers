/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo__init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:30:14 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/02 19:04:59 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	mx_init(t_philo *philo)
{
	if (pthread_mutex_init(&philo->mx_meal, NULL))
		return (1);
	if (pthread_mutex_init(&philo->mx_fork_r, NULL))
		return (philo__mx_destroy(philo, MX_MEAL), 1);
	return (0);
}

static void	fork__add_ptr(t_program *program, int i)
{
	if (i == program->philos_n - 1)
		program->philos[0].mx_fork_l = &program->philos[i].mx_fork_r;
	if (i)
		program->philos[i].mx_fork_l = &program->philos[i - 1].mx_fork_r;
}

int	philo__init(t_program *program, int i)
{
	program->philos[i].program = program;
	program->philos[i].index = i + 1;
	if (mx_init(&program->philos[i]))
		return (program__exit(program, i, CLEAN_PHILOS, EXIT_FAILURE));
	fork__add_ptr(program, i);
	return (0);
}
