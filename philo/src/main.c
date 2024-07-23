/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 07:53:35 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/23 01:17:42 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_program	program;

	return (
		parser(argc, argv)
		|| program_init(argv, &program)
		|| philos_init(&program)
		|| program_start(&program, START_WITHOUT_ERR)
		|| program_run(&program)
		|| program_exit(&program, 0, CLEAN_FULL, 0)
	);
}
