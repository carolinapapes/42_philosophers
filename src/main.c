/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 07:53:35 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/10 15:37:06 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

#define START_WITHOUT_ERR 0

extern inline int print_action(unsigned long time, int index, char *str)
{
	return (printf("%ld %d %s\n", time, index, str));
}

static int	init(t_program *program, char **argv)
{
	if (program__init(argv, program))
		return (1);
	if (philos__init(program))
		return (1);
	program__print(program);
	return (0);
}

static int	run(t_program *program)
{
	if (program__start(program, START_WITHOUT_ERR))
		return (1);
	if (program__status(program))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_program	program;

	printf("ARGC: %d\n", argc);
	if (init(&program, argv) || \
		run(&program))
		return (1);
	// program__exit(&program, 0, CLEAN_FULL);
	return (0);
}
