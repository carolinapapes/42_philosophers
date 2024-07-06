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
	if (MX_START & i)
		pthread_mutex_destroy(&program->mx_start);
	if (MX_END & i)
		pthread_mutex_destroy(&program->mx_end);
	if (MX_WRITE & i)
		pthread_mutex_destroy(&program->mx_write);
	return (0);
}
