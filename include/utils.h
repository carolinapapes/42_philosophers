/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:47:45 by capapes           #+#    #+#             */
/*   Updated: 2024/06/22 18:53:21 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

# define STR_INT_MAX "2147483647"
# define STR_INT_MIN "2147483648"

int	ft_isempty(char *s);
int	ft_issign(int c);
int ft_isdigit(int c);
int ft_strlen(char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_are_str_int(int argc, char *argv[]);
int	ft_isdigit(int c);

#endif