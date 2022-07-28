/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_thread.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:16:35 by groubaud          #+#    #+#             */
/*   Updated: 2022/07/28 11:29:43 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_THREAD_H
# define H_THREAD_H

# define INITIAL_STOCK   20
# define NB_CLIENTS      5

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>

/* Structure stockant les informations des threads clients et du magasin. */
typedef struct s_store
{
	int stock;

	pthread_t	thread_store;
	pthread_t	thread_clients[NB_CLIENTS];
	pthread_mutex_t mutex_stock;
	pthread_cond_t cond_stock;
	pthread_cond_t cond_client;	

}t_store;

static t_store	store = 
{
	.stock = INITIAL_STOCK,
	.mutex_stock = PTHREAD_MUTEX_INITIALIZER,
	.cond_stock = PTHREAD_COND_INITIALIZER,
	.cond_client = PTHREAD_COND_INITIALIZER,
};
#endif
