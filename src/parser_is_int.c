/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_is_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:16:32 by capapes           #+#    #+#             */
/*   Updated: 2024/07/20 14:24:40 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "utils.h"

static inline int	isempty(char *s)
{
	return (!*s);
}

static inline int	isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	isnbr(char *s)
{
	while (isdigit(*s))
		++s;
	if (!isempty(s))
		return (0);
	return (1);
}

static char	*get_non_zero_digit(char *s)
{
	while (*s && *s == '0')
		++s;
	return (s);
}

int	is_int(char *s, int type)
{
	int		len;

	if (!isnbr(s))
		return (0);
	s = get_non_zero_digit(s);
	if (type == NON_ZERO && isempty(s))
		return (0);
	len = ft_strlen(s);
	if (len != 10)
		return (len < 10);
	return (ft_strncmp(STR_INT_MAX, s, len) >= 0);
}
