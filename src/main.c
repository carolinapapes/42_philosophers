/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:45:04 by capapes           #+#    #+#             */
/*   Updated: 2024/06/30 21:30:27 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"

int	main(int argc, char **argv)
{
	t_program		program;

	if (!ph_parser(&program, argc, argv))
		return (1);
	ph_sim(&program);
	return (0);
}
