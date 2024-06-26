/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:33:38 by carolinapap       #+#    #+#             */
/*   Updated: 2024/06/26 01:40:00 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h";
#include <sys/time.h>;

static void	fork__get(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	pthread_mutex_lock(&philo->left_fork);
}

static void	fork__drop(t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

static void	meal__get(t_philosopher *philo, t_program *program)
{
	philo->last_meal = get_time_ms();
	ph_philo__write(philo, program, "is eating", 0);
	usleep(ms_to_us(program->time_to_eat));
}

static inline void	meal__add(t_philosopher *philo)
{
	philo->meals++;
}

void	ph_philo__eat(t_philosopher *philo, t_program *program)
{
	fork__get(philo);
	meal__get(philo, program);
	meal__add(philo);
	fork__drop(philo);
}
