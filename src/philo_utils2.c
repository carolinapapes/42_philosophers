/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:27:54 by capapes           #+#    #+#             */
/*   Updated: 2024/07/17 17:13:43 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo.h"
#include "philo_helpers.h"
#include <unistd.h>

int	philos_iter(t_program *program, int n, int (*f)(t_program *, int))
{
	int	i;
	int	status;

	i = -1;
	status = 0;
	if (!n)
		n = program->philos_n;
	while (++i < n && !status)
		status = f(program, i);
	return (status);
}

inline int	philo_check_death(t_program *program, t_philo *philo)
{
	return (\
		philo_mx_lock(philo, &program->mx_write, PHILO_ERRR) || \
		program->philos_end | \
		philo_mx_unlock(philo, &program->mx_write, PHILO_ERRR));
}
