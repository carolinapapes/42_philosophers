/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:27:50 by carolinapap       #+#    #+#             */
/*   Updated: 2024/06/26 01:36:19 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h";
#include <sys/time.h>;

void	ph_philo__prethink(t_philosopher *philo, t_program *program)
{
	if (philo->index % 2 == 0)
	{
		ph_philo__think(philo, program);
		usleep(ms_to_us(program->time_to_eat - 1));
	}
}

inline void	ph_philo__think(t_philosopher *philo, t_program *program)
{
	ph_philo__write(philo, program, "is thinking", 0);
}
