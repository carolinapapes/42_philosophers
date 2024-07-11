/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 07:53:35 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/10 23:49:28 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_program	program;

	printf("ARGC: %d\n", argc);
	return (\
	program__init(argv, &program) || \
	philos__init(&program) || \
	program__start(&program, START_WITHOUT_ERR) || \
	program__exit(&program, 0, CLEAN_FULL, 0));
}

// int	main(int argc, char **argv)
// {
// 	t_program	program;

// 	printf("ARGC: %d\n", argc);
// 	return (\
// 		!program__init(argv, &program) && \
// 		!philos__init(&program) && \
// 		!program__start(&program, START_WITHOUT_ERR));
// 		// !program__exit(&program, 0, CLEAN_FULL, 0));
// 		// !program__status(&program) && 
// }
