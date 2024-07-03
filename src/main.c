/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 07:53:35 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/03 01:03:47 by capapes          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_program	program;

	printf("argc: %d\n", argc);
	if (init(&program, argv))
		return (1);
	program__mx_print(&program, program__print);
	pthread_mutex_unlock(&program.mx_start);
	program__exit(&program, 0, CLEAN_FULL);
	return (0);
}
