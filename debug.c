/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:58:52 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/18 19:51:25 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Philo functions

// debuger extras
#include "philosophers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	philo_print(t_philo *philo)
{
	printf("\n\n -------------- PHILO %d \n", philo->index);
	printf("philo->index: %d\n", philo->index);
	printf("philo->meal_n: %d\n", philo->meal_n);
	printf("philo->meal_t: %lu\n", philo->meal_t);
	printf("philo->mx_fork_l: %p\n", philo->mx_fork_l);
	printf("philo->mx_fork_r: %p\n", &philo->mx_fork_r);
	printf("philo->mx_meal: %p\n", &philo->mx_meal);
	printf("philo->program: %p\n", philo->program);
}

// debuger extras
// #include <stdio.h>

void	program_print(t_program *program)
{
	printf("\n\nPROGRAM\n");
	printf("philos_n: %d\n", program->philos_n);
	printf("time_to_die: %lu\n", program->time_to_die);
	printf("time_to_eat: %lu\n", program->time_to_eat);
	printf("time_to_sleep: %lu\n", program->time_to_sleep);
	printf("meals_n: %d\n", program->meals_n);
	printf("philos: %p\n", &program->philos);
	printf("philos_end: %d\n", program->philos_end);
	printf("mx_end: %p\n", &program->mx_end);
	printf("mx_write: %p\n", &program->mx_write);
	printf("mx_start: %p\n", &program->mx_start);
}

void	program_mx_print(t_program *program, void (*f)(t_program *program))
{
	pthread_mutex_lock(&program->mx_write);
	f(program);
	pthread_mutex_unlock(&program->mx_write);
}

void	philo_mx_print(t_philo *philo, void (*f)(t_philo *philo))
{
	pthread_mutex_lock(&philo->program->mx_write);
	f(philo);
	pthread_mutex_unlock(&philo->program->mx_write);
}

void	program_print_end(int j, t_program *program, t_philo *philo)
{
	printf("----------------%d died\n", j + 1);
	printf("now %ld\n", get_time() - program->time_start);
	printf("last meal %ld\n", philo->meal_t);
	printf("time_to_die %ld\n", program->time_to_die);
}
