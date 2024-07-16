/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:23:11 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/16 14:57:43 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include "philo_helpers.h"

inline int	action(unsigned long time, int index, char *str)
{
	return (printf("%ld %d %s\n", time, index, str) == -1);
}

inline int	action__now(t_program *program, t_philo *philo, char *str, int err)
{
	long	time;

	time = (get_time() - program->time_start) * 0.001;
	return ((\
			program->philos_end || philo->err || time < 0 || \
			action(time, philo->index, str)) \
			&& exit_(philo, err));
}
