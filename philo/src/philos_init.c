/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:32:08 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/17 17:21:56 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo.h"
#include "philo_helpers.h"
#include <stdlib.h>
#include <string.h>

static int	allocate(t_program *program)
{
	program->philos = malloc(sizeof(t_philo) * program->philos_n);
	if (!program->philos)
		return (program_exit(program, 0, CLEAN_PROGRAM_MX, EXIT_FAILURE));
	memset(program->philos, 0, sizeof(t_philo) * program->philos_n);
	return (0);
}

static int	philo_th_create(t_program *program, int i)
{
	if (pthread_create(&program->philos[i].id, NULL,
		(void *)philo_rutine, &program->philos[i]))
		return (program_exit(program, i, CLEAN_START_PHILOS, EXIT_FAILURE));
	return (0);
}

int	philos_init(t_program *program)
{
	return (
		(allocate(program) && (ft_puterr(ERR_MALLOC), 1))
		|| (philos_iter(program, 0, philo_init) && put_err(ERR_MUTEX))
		|| (philos_iter(program, 0, philo_th_create) && put_err(ERR_THREAD)));
}
