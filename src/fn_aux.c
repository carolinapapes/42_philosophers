/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:11:43 by carolinapap       #+#    #+#             */
/*   Updated: 2024/07/03 23:54:36 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

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
	if (write(2, s, ft_strlen(s)))
		return ;
	return ;
}

long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}
