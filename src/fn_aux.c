/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:11:43 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/02 22:24:29 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_atoi__positive(const char *str)
{
	int	r;

	r = 0;
	while (*str >= '0' && *str <= '9')
		r = r * 10 + ((*str++) - '0');
	return (r);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_puterr(const char *s)
{
	write(2, s, ft_strlen(s));
}
