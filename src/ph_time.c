/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:17:39 by capapes           #+#    #+#             */
/*   Updated: 2024/06/26 23:45:45 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"
#include <sys/time.h>

inline unsigned long int	get_time_u(struct timeval tv)
{
	return (tv.tv_sec * 10000000000 + tv.tv_usec);
}

inline unsigned long int	time_diff_u(unsigned long int t1, \
		unsigned long int t2)
{
	return (t2 - t1);
}

inline unsigned long int	time_diff_tv(struct timeval t1, struct timeval t2)
{
	return (get_time_u(t2) - get_time_u(t1));
}

void	ph_get_timeof_day_ms(unsigned long int *time_u)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	*time_u = get_time_u(now);
}
