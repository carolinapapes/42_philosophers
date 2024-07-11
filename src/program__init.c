/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program__init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:28:05 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/11 18:03:28 by capapes          ###   ########.fr       */
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
	else
		program->meals_n = -1;
}

static inline int	mx_init_program(t_program *program, pthread_mutex_t *mutex, int err)
{
	return (pthread_mutex_init(mutex, NULL) \
	&& (program__mx_destroy(program, err), 1));
}

static int	mx_init(t_program *program)
{
	return (\
	mx_init_program(program, &program->mx_end, MX_NONE) || \
	mx_init_program(program, &program->mx_start, MX_END) || \
	mx_init_program(program, &program->mx_write, MX_END | MX_START) || \
	pthread_mutex_lock(&program->mx_start));
}

int	program__init(char **argv, t_program *program)
{
	initialize(program);
	values_set(argv, program);
	mx_init(program);
	return (0);
}
