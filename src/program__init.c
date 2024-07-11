/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program__init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:28:05 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/10 23:45:59 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "utils.h"
#include <string.h>

static inline void	initialize(t_program *program)
{
	memset(program, 0, sizeof(t_program));
}

// check if number doesnt overflow
static void	values_set(char **argv, t_program *program)
{
	program->philos_n = ft_atoi__positive(argv[1]);
	program->time_to_die = ft_atoi__positive(argv[2]) * 1000;
	program->time_to_eat = ft_atoi__positive(argv[3]) * 1000;
	program->time_to_sleep = ft_atoi__positive(argv[4]) * 1000;
	if (argv[5])
		program->meals_n = ft_atoi__positive(argv[5]);
}

static int	mx_init(t_program *program)
{
	return (\
	(pthread_mutex_init(&program->mx_end, NULL) \
	&& (program__mx_destroy(program, MX_NONE), 1)) || \
	(pthread_mutex_init(&program->mx_start, NULL) \
	&& (program__mx_destroy(program, MX_END), 1)) || \
	(pthread_mutex_init(&program->mx_write, NULL) \
	&& program__mx_destroy(program, MX_END | MX_START)));
}

int	program__init(char **argv, t_program *program)
{
	initialize(program);
	values_set(argv, program);
	mx_init(program);
	return (0);
}
