/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:11:56 by carolinapap       #+#    #+#             */
/*   Updated: 2024/06/30 21:13:21 by carolinapap      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_philosophers.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isnbr(char *s)
{
	while (ft_isdigit(*s))
		++s;
	if (!ft_isempty(s))
		return (0);
	return (1);
}

char	*ft_get_non_zero_digit(char *s)
{
	while (*s && *s == '0')
		++s;
	return (s);
}

int	ft_is_str_int(char *s)
{
	int		len;

	if (!ft_isnbr(s))
		return (0);
	s = ft_get_non_zero_digit(s);
	len = ft_strlen(s);
	if (len == 0)
		return (0);
	if (len != 10)
		return (len < 10);
	return (ft_strncmp(STR_INT_MAX, s, len) >= 0);
}

int	ft_are_str_int(int argc, char *argv[])
{
	int	i;
	int	isvalid;

	i = 0;
	isvalid = 1;
	while (isvalid && ++i < argc)
		isvalid = ft_is_str_int(argv[i]);
	return (isvalid);
}
