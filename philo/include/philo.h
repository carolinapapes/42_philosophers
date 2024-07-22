/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:27:53 by capapes           #+#    #+#             */
/*   Updated: 2024/07/22 18:48:15 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// PHILO CLEAN ACTIONS
# define PHILO_ERRR				    0  	// UNLOCK FORK RIGHT
# define PHILO_ERR_WRITE		    1 	// UNLOCK WRITE
# define PHILO_ERR_FORK_RIGHT		2  	// UNLOCK FORK RIGHT
# define PHILO_ERR_FORK_LEFT		4  	// UNLOCK FORK LEFT
# define PHILO_ERR_FORK_LEFT_FIRST  8   // UNLOCK FORK LEFT
# define PHILO_ERR_FORKS_R  	    6  	// UNLOCK FORK RIGHT | UNLOCK FORK LEFT
# define PHILO_ERR_FORKS_L          10  // UNLOCK FORK LEFT | UNLOCK FORK RIGHT
# define PHILO_ERR_START		    16 	// UNLOCK START
# define PHILO_ERR_FORK_RIGHT_INIT	32 	// DESTROY FORK RIGHT
# define PHILO_ERR_NO_WRITE		    64 	// NO UNLOCK WRITE

# define EAT 					"is eating"
# define SLEEP 					"is sleeping"
# define THINK 					"is thinking"
# define DEAD 					"died"
# define FORK 					"has taken a fork"

#endif