/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program__utils.c                                	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:28:09 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/02 19:47:44 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	program__mx_destroy(t_program *program, int i)
{
	i & MX_START && pthread_mutex_destroy(&program->mx_start);
	i & MX_END && pthread_mutex_destroy(&program->mx_end);
	i & MX_WRITE && pthread_mutex_destroy(&program->mx_write);
	return (0);
}

inline int	program__mx_init(t_program *program, \
	pthread_mutex_t *mutex, int err)
{
	return (pthread_mutex_init(mutex, NULL) \
	&& (program__mx_destroy(program, err), 1));
}

inline int	program__mx_lock(t_program *program, \
	pthread_mutex_t *mutex, int err)
{
	return (pthread_mutex_lock(mutex) \
	&& (program__mx_destroy(program, err), 1));
}
