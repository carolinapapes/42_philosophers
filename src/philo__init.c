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
#include "philo.h"
#include "philo_helpers.h"

static int	_init(t_philo *philo)
{
	return (\
		philo__mx_init(philo, &philo->mx_meal, PHILO_ERRR) || \
		philo__mx_init(philo, &philo->mx_fork_r, PHILO_ERR_MEAL_INIT));
}

static void	_fork__add_ptr(t_program *program, int i)
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
	if (_init(&program->philos[i]))
		return (program__exit(program, i, CLEAN_PHILOS, EXIT_FAILURE));
	_fork__add_ptr(program, i);
	//philo__print(&program->philos[i]);
	return (0);
}
