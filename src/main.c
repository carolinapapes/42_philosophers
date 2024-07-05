/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 07:53:35 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/05 23:11:45 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

static int	init(t_program *program, char **argv)
{
	if (program__init(argv, program))
		return (1);
	if (philos__init(program))
		return (1);
	return (0);
}

void	program__start(t_program *program, int err)
{
	if (err)
		program->philos_end = 1;
	program->time_start = get_time();
	pthread_mutex_unlock(&program->mx_start);
}

static void	run(t_program *program)
{
	program__start(program, 0);
	program__check(program);
}

int	main(int argc, char **argv)
{
	t_program	program;

	printf("ARGC: %d\n", argc);
	if (init(&program, argv))
		return (1);
	run(&program);
	program__exit(&program, 0, CLEAN_FULL);
	return (0);
}
