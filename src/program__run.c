/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program__run.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:38:47 by capapes           #+#    #+#             */
/*   Updated: 2024/07/10 17:34:14 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	program__start(t_program *program, int err)
{
	printf("%s\n", __func__);
	if (err)
		program->philos_end = 1;
	program->time_start = get_time();
	pthread_mutex_unlock(&program->mx_start);
	return (0);
}

/*
*	Every time it fails, set program->philos_end to 1.
*/
int	program__status(t_program *program)
{
	printf("%s\n", __func__);
	int			j;
	int			k;
	long int	time;

	time = program->time_start + program->time_to_die;
	while (!program->philos_end)
	{
		j = -1;
		k = 0;
		while (++j < program->philos_n)
			if (mx__meals(program, &program->philos[j], time, &k))
				return (1);
	}
	return (0);
}
