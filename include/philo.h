/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:27:53 by capapes           #+#    #+#             */
/*   Updated: 2024/07/18 20:10:24 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// PHILO CLEAN ACTIONS
# define PHILO_ERRR				    0  	// UNLOCK FORK RIGHT
# define PHILO_ERR_WRITE		    1 	// UNLOCK WRITE
# define PHILO_ERR_FORK_RIGHT		2  	// UNLOCK FORK RIGHT
# define PHILO_ERR_FORK_LEFT		4  	// UNLOCK FORK LEFT
# define PHILO_ERR_FORKS		    6  	// UNLOCK FORK RIGHT | UNLOCK FORK LEFT
# define PHILO_ERR_MEAL			    8 	// UNLOCK MEAL
# define PHILO_ERR_START		    16 	// UNLOCK START
# define PHILO_ERR_MEAL_INIT	    32 	// DESTROY MEAL
# define PHILO_ERR_FORK_RIGHT_INIT	64 	// DESTROY FORK RIGHT

# define EAT 					"is eating"
# define SLEEP 					"is sleeping"
# define THINK 					"is thinking"
# define DEAD 					"died"
# define FORK 					"has taken a fork"

#endif