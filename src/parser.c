/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:56:37 by capapes           #+#    #+#             */
/*   Updated: 2024/07/15 14:19:40 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "utils.h"

int	_are_str_int(int argc, char *argv[])
{
	int	i;
	int	isvalid;

	i = 0;
	isvalid = 1;
	while (isvalid && ++i < argc)
		isvalid = is_int(argv[i], NON_ZERO);
	return (isvalid);
}

int	ph_parser(int argc, char *argv[])
{
	return (((\
		argc < 5 || argc > 6) \
		&& printf("Error: invalid number of arguments\n")) || \
		(!_are_str_int(argc, argv) \
		&& printf("Error: invalid argument. Must be a number > 0\n")));
}
