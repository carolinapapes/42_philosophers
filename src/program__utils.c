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
