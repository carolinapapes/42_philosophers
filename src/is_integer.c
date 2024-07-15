/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:16:32 by capapes           #+#    #+#             */
/*   Updated: 2024/07/13 11:21:00 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "utils.h"

static inline int	_isempty(char *s)
{
	return (!*s);
}

static inline int	_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	_isnbr(char *s)
{
	while (_isdigit(*s))
		++s;
	if (!_isempty(s))
		return (0);
	return (1);
}

static char	*_get_non_zero_digit(char *s)
{
	while (*s && *s == '0')
		++s;
	return (s);
}

int	ft_is_str_int(char *s, int type)
{
	int		len;

	if (!_isnbr(s))
		return (0);
	s = _get_non_zero_digit(s);
	if (type == NON_ZERO && !_isempty(s))
		return (0);
	len = ft_strlen(s);
	if (len != 10)
		return (len < 10);
	return (ft_strncmp(STR_INT_MAX, s, len) >= 0);
}
