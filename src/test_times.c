/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_times.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:07:09 by capapes           #+#    #+#             */
/*   Updated: 2024/06/26 20:34:59 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

unsigned long int	get_time_usec(struct timeval tv)
{
	return ((tv.tv_sec % 1000) * 1000 + tv.tv_usec * 0.001);
}

inline unsigned long int	ms_to_us(unsigned long int ms)
{
	return (ms * 1000);
}

inline unsigned long int	get_time_diff(struct timeval sim_init, struct timeval sim_curr)
{
	return (get_time_ms(sim_curr) - get_time_ms(sim_init));
}



int	main(void)
{
	struct timeval	tv_1;
	struct timeval	tv_2;
	unsigned long int	time_to_die;
	unsigned long int	time_to_eat;

	srand(time(NULL));
	time_to_die = get_random_ms(1000);
	time_to_eat = get_random_ms(1000);
	printf("im: %s\n", __func__);
	printf("time to die: %u\n", time_to_die);
	printf("time to eat: %u\n", time_to_eat);
	gettimeofday(&tv_1, NULL);
	usleep(ms_to_us(time_to_eat));
	gettimeofday(&tv_2, NULL);
	printf("time1: %u\n", get_time_ms(tv_1));
	printf("time2: %u\n", get_time_ms(tv_2));
	is_philo_dead(tv_1, tv_2, time_to_die);
	return (0);
}


void	get_timeval_diff(struct timeval *start, struct timeval *end)
{
	unsigned long int	elapsed_time;

	elapsed_time = (start->tv_sec - end->tv_sec) * 1000 + (start->tv_usec - end->tv_usec) * 0.001; 
}