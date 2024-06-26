/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:45:04 by capapes           #+#    #+#             */
/*   Updated: 2024/06/26 00:17:03 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ph_philosophers.h"
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

unsigned int	get_time_ms(struct timeval tv)
{
	return (tv.tv_sec * 1000 + tv.tv_usec * 0.001);
}

unsigned int	ms_to_us(unsigned int ms)
{
	return (ms * 1000);
}

unsigned int	get_random(unsigned int max)
{
	return (rand() % max + 1);
}

unsigned int	get_time_diff(struct timeval sim_init, struct timeval sim_curr)
{
	return (get_time_ms(sim_curr) - get_time_ms(sim_init));
}

void	is_philo_dead(struct timeval init, struct timeval curr, unsigned int time_to_die)
{
	unsigned int	time_diff;

	time_diff = get_time_diff(init, curr);
	if (time_diff > time_to_die)
		printf("I'm dead\n");
	else
		printf("I'm alive\n");
}

static void	init(t_program *program)
{
	program->n_philosophers = get_random(100);
	program->time_to_die = get_random(1000);
	program->time_to_eat = get_random(1000);
	program->time_to_sleep = get_random(1000);
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
	struct timeval	tv_2;

	srand(time(NULL));
	program__init(&program);
	program__print(&program);
	gettimeofday(&program.start_time, NULL);
	return (0);
}
