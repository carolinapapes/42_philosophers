/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser__is_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:16:32 by capapes           #+#    #+#             */
/*   Updated: 2024/07/19 11:26:21 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "utils.h"

static int	is_nbr(char *s)
{
	while (*s >= '0' && *s <= '9')
		s++;
	return (!*s);
}

static int	str_other_than(char **s, char c)
{
	while (**s == c)
		++(*s);
	printf("str_not_chr: %d\n", !(**s));
	return (**s);
}

static int	get_non_zero(char **s, int non_zero)
{
	int	i;

	i = str_other_than(s, '0');
	if (non_zero && i)
		return (1);
	return (i);
}

static int	is_int_range(char *s)
{
	int		len;

	len = ft_strlen(s);
	printf("is_int_range: %d\n", len);
	if (len != 10)
		return (len < 10);
	return (ft_strncmp(STR_INT_MAX, s, len) >= 0);
}

int	is_int(char *s, int is_zero)
{
	return (\
		is_nbr(s) && \
		get_non_zero(&s, is_zero) && \
		is_int_range(s));
}
