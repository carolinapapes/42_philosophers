/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:55:56 by capapes           #+#    #+#             */
/*   Updated: 2024/06/30 22:06:43 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"

static void	initialize(t_program *program, int argc, char *argv[])
{
	program->n_philosophers = ft_atoi(argv[1]);
	program->time_to_die = ft_atoi(argv[2]) * 1000;
	program->time_to_eat = ft_atoi(argv[3]) * 1000;
	program->time_to_sleep = ft_atoi(argv[4]) * 1000;
	program->is_dead = 0;
	if (argc == 6)
		program->n_meals = ft_atoi(argv[5]);
	else
		program->n_meals = 0;
}

int	ph_parser(t_program *program, int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: invalid number of arguments\n");
		return (0);
	}
	if (!ft_are_str_int(argc, argv))
	{
		printf("Error: invalid argument. Must be a number > 0\n");
		return (0);
	}
	initialize(program, argc, argv);
	return (1);
}
