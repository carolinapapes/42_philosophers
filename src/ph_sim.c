/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_sim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:32:07 by capapes           #+#    #+#             */
/*   Updated: 2024/06/30 14:50:07 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <sys/time.h>
#include <stdlib.h>

void	free_philos(t_program *program)
{
	int	i;

	i = -1;
	while (++i < program->n_philosophers)
		pthread_mutex_destroy(&program->philos[i].right_fork);
	free(program->philos);
}

static void	end(t_program *program)
{
	int	i;

	ph_philos__deaths(program);
	i = -1;
	while (++i < program->n_philosophers)
		pthread_join(program->philos[i].id, NULL);
	free_philos(program);
}

static void	launch(t_program *program)
{
	ph_get_timeof_day_u(&program->start_time_u);
	pthread_mutex_unlock(&program->start);
	pthread_mutex_destroy(&program->start);
}

static void	initialize(t_program *program)
{
	pthread_mutex_init(&program->start, NULL);
	pthread_mutex_init(&program->write, NULL);
	pthread_mutex_lock(&program->start);
	ph_philo__init(program);
}

void	ph_sim(t_program *program)
{
	initialize(program);
	launch(program);
	end(program);
	return ;
}

// void	print_philo(t_philosopher *philo)
// {
// 	printf("\n-----------------------------------------------\n\n");
// 	printf("PHILOSOPHER %p", philo);
// 	printf(" %d\n", philo->index);
// 	printf("| id\t\t%lu\n", philo->id);
// 	printf("| lfork\t\t%p\n", philo->left_fork);
// 	printf("| rfork\t\t%p\n", &philo->right_fork);
// 	printf("| meals\t\t%d\n", philo->meals);
// 	printf("| tmeal\t\t%llu\n", philo->last_meal);
// 	printf("| prog\t\t%p\n\n", philo->program);
// }

// void	print_philos(t_philosopher *philos, t_program *program)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < program->n_philosophers)
// 		print_philo(&philos[i]);
// }