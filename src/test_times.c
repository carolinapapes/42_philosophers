/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_times.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:07:09 by capapes           #+#    #+#             */
/*   Updated: 2024/06/24 12:24:46 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

unsigned int get_time_ms(struct timeval tv)
{
    return(tv.tv_sec * 1000 + tv.tv_usec * 0.001);
}

unsigned int ms_to_us(unsigned int ms)
{
    return(ms * 1000);
}

unsigned int get_random_ms(unsigned int max)
{
    return(rand() % max + 1);
}

unsigned int get_time_diff(struct timeval sim_init, struct timeval sim_curr)
{
    return(get_time_ms(sim_curr) - get_time_ms(sim_init));
}

void is_philo_dead(struct timeval init, struct timeval curr, unsigned int time_to_die)
{
    unsigned int    time_diff;
    time_diff = get_time_diff(init, curr);
    printf("Elapsed time: %u\n", time_diff);
    if (time_diff > time_to_die)
        printf("I'm dead\n");
    else
        printf("I'm alive\n");   
}


int	main(void)
{
    struct timeval tv_1;
    struct timeval tv_2;
    unsigned int time_to_die;
    unsigned int time_to_eat;

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
    return(0);
}
