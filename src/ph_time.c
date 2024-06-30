/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:17:39 by capapes           #+#    #+#             */
/*   Updated: 2024/06/30 22:06:54 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"

static inline unsigned long int	get_time_u(struct timeval tv)
{
	return ((tv.tv_sec * 1000000) + tv.tv_usec);
}

void	ph_get_timeof_day_u(unsigned long int*time_u)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	// should return if failed
	*time_u = get_time_u(now);
}
