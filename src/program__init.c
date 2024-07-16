/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program__init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:28:05 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/16 16:43:48 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "utils.h"
#include <string.h>

static void	_set(char **argv, t_program *program)
{
	memset(program, 0, sizeof(t_program));
	program->philos_n = atoi__parser(argv[1]);
	program->time_to_die = atoi__parser(argv[2]) * 1000;
	program->time_to_eat = atoi__parser(argv[3]) * 1000;
	program->time_to_sleep = atoi__parser(argv[4]) * 1000;
	program->meals_n = -1;
	if (argv[5])
		program->meals_n = atoi__parser(argv[5]);
}

static inline int	_init(t_program *program)
{
	return ((\
	program__mx_init(program, &program->mx_end, MX_NONE) || \
	program__mx_init(program, &program->mx_start, MX_END) || \
	program__mx_init(program, &program->mx_write, MX_END | MX_START)) || \
	program__mx_lock(program, &program->mx_start, MX_FULL));
}

int	program__init(char **argv, t_program *program)
{
	_set(argv, program);
	return (_init(program));
}
