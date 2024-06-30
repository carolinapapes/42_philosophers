/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:45:04 by capapes           #+#    #+#             */
/*   Updated: 2024/06/30 21:10:50 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"

int	main(int argc, char **argv)
{
	t_program		program;

	if (!ph_parser__init(&program, argc, argv))
		return (1);
	ph_sim(&program);
	return (0);
}
