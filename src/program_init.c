/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_init.c                                    :+:      :+:    :+:   */
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
	program->philos_n = atoi_parser(argv[1]);
	program->time_to_die = atoi_parser(argv[2]) * 1000;
	program->time_to_eat = atoi_parser(argv[3]) * 1000;
	program->time_to_sleep = atoi_parser(argv[4]) * 1000;
	program->meals_n = -1;
	if (argv[5])
		program->meals_n = atoi_parser(argv[5]);
	if (!(program->philos_n & 1))
		program->rutine = 1;
}

static inline int	_init(t_program *program)
{
	return ((\
	program_mx_init(program, &program->mx_end, MX_NONE) || \
	program_mx_init(program, &program->mx_start, MX_END) || \
	program_mx_init(program, &program->mx_write, MX_END | MX_START)) || \
	program_mx_lock(program, &program->mx_start, MX_FULL));
}

int	program_init(char **argv, t_program *program)
{
	_set(argv, program);
	return (_init(program));
}
