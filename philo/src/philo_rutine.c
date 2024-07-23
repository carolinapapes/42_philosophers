/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:56:07 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/23 00:50:47 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo.h"
#include "philo_helpers.h"

static inline int	sleep(t_program *program, t_philo *philo)
{
	return (
		print_now(program, philo, SLEEP, PHILO_ERRR)
		|| philo_usleep(philo, program->time_to_sleep, PHILO_ERRR));
}

static inline int	think(t_program *program, t_philo *philo)
{
	return (print_now(program, philo, THINK, PHILO_ERRR));
}

static inline int	eat(t_program *program, t_philo *philo)
{
	return (
		forks_get(philo, program)
		|| philo_meal(philo, program)
		| forks_drop(philo));
}

void	philo_rutine(t_philo *philo)
{
	t_program	*program;

	program = philo->program;
	set_start(program, philo);
	while (
		!philo->err
		&& !eat(program, philo)
		&& !sleep(program, philo)
		&& !think(program, philo))
		;
}
