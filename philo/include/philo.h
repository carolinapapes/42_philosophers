/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:27:53 by capapes           #+#    #+#             */
/*   Updated: 2024/07/22 23:49:11 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// PHILO CLEAN ACTIONS
# define PHILO_ERRR				    0  	// UNLOCK FORK RIGHT
# define PHILO_ERR_WRITE		    1 	// UNLOCK WRITE
# define PHILO_ERR_FIRST		    2	// UNLOCK FORK FIRST
# define PHILO_ERR_FORKS_UN			4	// UNLOCK FORK FIRST && SECOND

# define EAT 					"is eating"
# define SLEEP 					"is sleeping"
# define THINK 					"is thinking"
# define DEAD 					"died"
# define FORK 					"has taken a fork"

#endif