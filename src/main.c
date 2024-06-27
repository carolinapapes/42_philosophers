/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:45:04 by capapes           #+#    #+#             */
/*   Updated: 2024/06/26 23:48:45 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ph_philosophers.h"
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

static inline unsigned long int	random(unsigned long int max)
{
	return (rand() % max + 1);
}

static void	init(t_program *program)
{
	program->n_philosophers = random(100);
	program->time_to_die = random(1000);
	program->time_to_eat = random(1000);
	program->time_to_sleep = random(1000);
}

static void	print(t_program *program)
{
	printf("n_philosophers: %u\n", program->n_philosophers);
	printf("time_to_die: %u\n", program->time_to_die);
	printf("time_to_eat: %u\n", program->time_to_eat);
	printf("time_to_sleep: %u\n", program->time_to_sleep);
}

int	main(void)
{
	t_program		program;

	srand(time(NULL));
	program__init(&program);
	program__print(&program);
	ph_sim(&program);
	return (0);
}
