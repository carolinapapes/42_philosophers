/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 07:53:35 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/03 20:41:41 by capapes          ###   ########.fr       */
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
	program.time_start = get_time();
	pthread_mutex_unlock(&program.mx_start);
	philo__mx_checkdeaths(&program);
	program__exit(&program, 0, CLEAN_FULL);
	return (0);
}
