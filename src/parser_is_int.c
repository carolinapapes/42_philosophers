/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_is_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:16:32 by capapes           #+#    #+#             */
/*   Updated: 2024/07/20 16:02:17 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "utils.h"

static inline int	isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	isnbr(char *s)
{
	while (isdigit(*s))
		++s;
	return (*s);
}

static int	get_non_zero_digit(char **s)
{
	while (**s == '0')
		++(*s);
	return (!(**s));
}

static int	is_positive_int(char *s)
{
	int		len;

	len = ft_strlen(s);
	if (len != 10)
		return (len > 10);
	return (ft_strncmp(STR_INT_MAX, s, len) < 0);
}

// non zero positive integer
inline int	is_int(char **s)
{
	return (\
		isnbr(*s) || \
		get_non_zero_digit(s) || \
		is_positive_int(*s));
}
