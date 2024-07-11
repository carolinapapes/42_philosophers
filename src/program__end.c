/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program__end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:01:31 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/11 17:57:58 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

int	philo__mx_destroy(t_philo *philo, int i)
{
	i & MX_MEAL && pthread_mutex_destroy(&philo->mx_meal);
	i & MX_FORK && pthread_mutex_destroy(&philo->mx_fork_r);
	return (0);
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

int	program__exit(t_program *program, int thphilos_n, int i, int status)
{
	if (thphilos_n == 0)
		thphilos_n = program->philos_n;
	i & CLEAN_START && program__start(program, ERR_INIT_FAIL);
	i & CLEAN_FULL && philos__iter(program, thphilos_n, philos__th_join);
	i & CLEAN_PHILOS && philos__mx_destroy(program, thphilos_n);
	i & CLEAN_FREE && philos__free(program);
	i & CLEAN_PROGRAM && program__mx_destroy(program, MX_PROGRAM);
	return (status);
}
