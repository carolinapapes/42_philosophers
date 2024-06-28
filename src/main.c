/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:45:04 by capapes           #+#    #+#             */
/*   Updated: 2024/06/28 17:07:07 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 

inline unsigned long int	get_random(unsigned long int max)
{
	return ((unsigned long int)rand() % max + 1);
}

static void	init(t_program *program)
{
	program->n_philosophers = get_random(10);
	program->time_to_die = get_random(140) + 60;
	program->time_to_eat = get_random(140) + 60;
	program->time_to_sleep = get_random(140) + 60;
}

static void	print(t_program *program)
{
	printf("n_philosophers: %d\n", program->n_philosophers);
	printf("time_to_die: %lu\n", program->time_to_die);
	printf("time_to_eat: %lu\n", program->time_to_eat);
	printf("time_to_sleep: %lu\n", program->time_to_sleep);
}

int	main(void)
{
	t_program		program;

	srand(time(NULL));
	init(&program);
	print(&program);
	ph_sim(&program);
	return (0);
}
