/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:56:37 by capapes           #+#    #+#             */
/*   Updated: 2024/07/11 18:19:16 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

# define STR_INT_MAX "2147483647"


int	ft_isempty(char *s)
{
	return (!*s);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

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

int	ph_parser(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: invalid number of arguments\n");
		return (1);
	}
	if (!ft_are_str_int(argc, argv))
	{
		printf("Error: invalid argument. Must be a number > 0\n");
		return (1);
	}
	return (0);
}
