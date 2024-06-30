/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:55:56 by capapes           #+#    #+#             */
/*   Updated: 2024/06/30 15:44:22 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"

int	ft_isnbr(char *s)
{
	// if (ft_issign(*s) && ft_isdigit(*(s + 1)))
	// 	++s;
	while (ft_isdigit(*s))
		++s;
	if (!ft_isempty(s))
		return (0);
	return (1);
}

char	*ft_get_non_zero_digit(char *s)
{
	while (*s && *s == '0')
		++s;
	return (s);
}

int	ft_is_str_int(char *s)
{
	char	sign;
	int		len;

	if (!ft_isnbr(s))
		return (0);
	sign = *s;
	s = ft_get_non_zero_digit(s);
	len = ft_strlen(s);
	if (len == 0)
		return (0);
	if (len != 10)
		return (len < 10);

	return (ft_strncmp(STR_INT_MAX, s, len) >= 0);
}

int	ft_are_str_int(int argc, char *argv[])
{
	int	i;
	int	isvalid;

	i = -1;
	isvalid = 1;
	while (isvalid && ++i < argc)
		isvalid = ft_is_str_int(argv[i]);
	if (argc < 5 || argc > 6)
		isvalid = 0;
	if (!isvalid)
		return (0);
	return (1);
}

int ph_parser__init(t_program *program, int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: invalid number of arguments\n");
		return (0);
	}
	if (!ft_are_str_int(argc, argv))
	{
		printf("Error: invalid argument. Must be a numeber > 0\n");
		return (0);
	}
	program->n_philosophers = ft_atoi(argv[1]);
	program->time_to_die = ft_atoi(argv[2]);
	program->time_to_eat = ft_atoi(argv[3]);
	program->time_to_sleep = ft_atoi(argv[4]);
	program->is_dead = 0;
	if (argc == 6)
		program->n_meals = ft_atoi(argv[5]);
	else
		program->n_meals = -1;
	return (1);
}
