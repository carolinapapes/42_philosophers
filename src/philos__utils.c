/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos__utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:37:31 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/04 20:07:41 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

int	philos__iter(t_program *program, int n, int (*f)(t_program *, int))
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < n && !j)
		j = f(program, i);
	return (j);
}
