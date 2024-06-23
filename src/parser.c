/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:55:56 by capapes           #+#    #+#             */
/*   Updated: 2024/06/22 21:03:55 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_isnbr(char *s)
{
	if (ft_issign(*s) && ft_isdigit(*(s + 1)))
		++s;
	while (ft_isdigit(*s))
		++s;
	if (!ft_isempty(s))
		return (0);
	return (1);
}

char	*ft_get_non_zero_digit(char *s)
{
	if (ft_issign(*s))
		++s;
	while (*s && *s == '0')
		++s;
	return (s);
}

int	ft_is_str_int(char *s)
{
	char	sign;
	int		len;

	if (!ft_isnbr(s))
		return (0);
	sign = *s;
	s = ft_get_non_zero_digit(s);
	len = ft_strlen(s);
	if (len != 10)
		return (len < 10);
	if (sign == '-')
		return (ft_strncmp(STR_INT_MIN, s, len) >= 0);
	return (ft_strncmp(STR_INT_MAX, s, len) >= 0);
}

int	ft_are_str_int(int argc, char *argv[])
{
	int	i;
	int	isvalid;

	i = -1;
	isvalid = 1;
	while (isvalid && ++i < argc)
		isvalid = ft_is_str_int(argv[i]);
	if (!isvalid)
		return (0);
	return (1);
}
