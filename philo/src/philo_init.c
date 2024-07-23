/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:30:14 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/02 19:04:59 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo.h"
#include "philo_helpers.h"

static int	init(t_philo *philo)
{
	return (philo_mx_init(philo, &philo->mx_fork_r, PHILO_ERRR));
}

static void	forks_order(t_program *program, int i, int hand)
{
	if (hand == RIGHTY)
	{
		program->philos[i].fork_first = &program->philos[i].mx_fork_r;
		program->philos[i].fork_second = program->philos[i].mx_fork_l;
		return ;
	}
		program->philos[i].fork_first = program->philos[i].mx_fork_l;
		program->philos[i].fork_second = &program->philos[i].mx_fork_r;
}

static void	fork_add_l(t_program *program, int i)
{
	if (i == program->philos_n - 1)
	{
		program->philos[0].mx_fork_l = &program->philos[i].mx_fork_r;
		forks_order(program, 0, RIGHTY);
	}
	if (i)
	{
		program->philos[i].mx_fork_l = &program->philos[i - 1].mx_fork_r;
		if (program->rutine && (program->philos[i].index) & 1)
			forks_order(program, i, LEFTY);
		else
			forks_order(program, i, RIGHTY);
	}
}

int	philo_init(t_program *program, int i)
{
	program->philos[i].program = program;
	program->philos[i].index = i + 1;
	if (init(&program->philos[i]))
		return (program_exit(program, i, CLEAN_PHILOS, EXIT_FAILURE));
	fork_add_l(program, i);
	return (0);
}
