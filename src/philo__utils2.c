/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo__utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:27:54 by capapes           #+#    #+#             */
/*   Updated: 2024/07/13 11:28:19 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philos__iter(t_program *program, int n, int (*f)(t_program *, int))
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (!n)
		n = program->philos_n;
	while (++i < n && !j)
		j = f(program, i);
	return (j);
}
