/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 07:53:35 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/10 17:34:58 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

#define START_WITHOUT_ERR 0

static int	init(t_program *program, char **argv)
{
	printf("INIT\n");
	return (\
	!program__init(argv, program) && \
	!philos__init(program));
}

static int	run(t_program *program)
{
	printf("RUN\n");
	return (\
	!program__start(program, START_WITHOUT_ERR) && \
	!program__status(program));
}

int	main(int argc, char **argv)
{
	t_program	program;

	printf("ARGC: %d\n", argc);
	if (init(&program, argv) && run(&program))
		return (1);
	// program__exit(&program, 0, CLEAN_FULL);
	return (0);
}
