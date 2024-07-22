/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:56:37 by capapes           #+#    #+#             */
/*   Updated: 2024/07/20 20:54:02 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "utils.h"

inline int	put_err(char *str)
{
	return (ft_puterr(str), 1);
}

int	type(int argc, char *argv[])
{
	while (argc > 1)
		if (is_not_int(&argv[--argc]))
			return (put_err(ERR_ARGS_INT));
	return (0);
}

static inline int	quantity(int argc)
{
	return (\
		argc < 5 | argc > 6 \
		&& put_err(ERR_ARGS_QTY));
}

int	parser(int argc, char *argv[])
{
	return (\
		quantity(argc) || \
		type(argc, argv));
}
