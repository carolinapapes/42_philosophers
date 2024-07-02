/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo__clean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:01:31 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/02 22:24:33 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

void	philo__mx_destroy(t_philo *philo, int i)
{
	if (MX_MEAL & i)
		pthread_mutex_destroy(&philo->mx_meal);
	if (MX_FORK & i)
		pthread_mutex_destroy(&philo->mx_fork_r);
}

int	philos__mx_destroy(t_program *program, int i)
{
	philo__mx_destroy(&(program->philos[i]), MX_PHILO);
	return (0);
}

int	philos__th_join(t_program *program, int i)
{
	if (pthread_join(program->philos[i].id, NULL))
		return (1);
	return (0);
}

int	philos__free(t_program *program)
{
	free(program->philos);
	return (0);
}

//! check what happens when thread fails to create with n 
//! launch program wait only for threads created
int	program__exit(t_program *program, int n, int i)
{
	if (n == 0)
		n = program->philos_n;
	if (CLEAN_FULL & i)
		philos__iter(program, n, philos__th_join);
	if (CLEAN_PHILOS & i)
		philos__mx_destroy(program, n);
	if (CLEAN_FREE & i)
		philos__free(program);
	if (CLEAN_PROGRAM & i)
		program__mx_destroy(program, MX_PROGRAM);
	return (0);
}
