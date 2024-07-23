/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:01:31 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/18 16:32:47 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>
#include "philo_helpers.h"

int	philos_mx_destroy(t_program *program, int n)
{
	t_philo	philo;
	int		i;

	i = -1;
	while (++i < n)
	{
		philo = program->philos[i];
		pthread_mutex_destroy(&philo.mx_fork_r);
	}
	return (0);
}

int	philos_th_join(t_program *program, int i)
{
	if (pthread_join(program->philos[i].id, NULL))
		return (1);
	return (0);
}

int	philos_free(t_program *program)
{
	free(program->philos);
	return (0);
}

int	program_exit(t_program *program, int thphilos_n, int i, int status)
{
	if (thphilos_n == 0)
		thphilos_n = program->philos_n;
	i & CLEAN_START && program_start(program, CLEAN_INIT_FAIL);
	i & CLEAN_FULL && philos_iter(program, thphilos_n, philos_th_join);
	i & CLEAN_PHILOS && philos_mx_destroy(program, thphilos_n);
	i & CLEAN_FREE && philos_free(program);
	i & CLEAN_PROGRAM_MX && program_mx_destroy(program, MX_PROGRAM);
	return (status);
}
