/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo__actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:23:57 by carolinapap       #+#    #+#             */
/*   Updated: 2024/06/26 00:20:03 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h";

void	ph_philo__sleep(t_philosopher *philo, t_program *program)
{
	ph_philo__write(philo, program, "is sleeping", 0);
	usleep(ms_to_us(program->time_to_sleep));
}
