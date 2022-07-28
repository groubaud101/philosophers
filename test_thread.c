/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 08:57:36 by groubaud          #+#    #+#             */
/*   Updated: 2022/07/28 11:31:34 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -lpthread -D_REENTRANT
#include "h_thread.h"

//int pthread_create (pthread_t * thread, pthread_attr_t * attr, void * (* start_routine) (void *), void * arg);

static int	get_random(int max)
{
   double val;
 
   val = (double) max * rand ();
   val = val / (RAND_MAX + 1.0);
 
   return ((int) val);
}

/* Fonction pour le thread du magasin. */
static void	*fn_store(void *p_data)
{
	while (1)
	{
		pthread_mutex_lock(&store.mutex_stock);
		pthread_cond_wait (& store.cond_stock, & store.mutex_stock);

		store.stock = INITIAL_STOCK;
		printf("\nRemplissage du stock de %d articles !\n\n", store.stock);

		pthread_cond_signal (& store.cond_client);
		pthread_mutex_unlock(&store.mutex_stock);
	}

	return NULL;
}
 
/* Fonction pour les threads des clients. */
static void	*fn_clients(void *p_data)
{
	int *a = (int*)p_data;
	int nb = *a;

	while (1)
	{
		int	val = get_random(6);

		sleep(get_random (3));
		pthread_mutex_lock(&store.mutex_stock);
		if (val > store.stock)
		{
			pthread_cond_signal(&store.cond_stock);
			pthread_cond_wait(&store.cond_client, &store.mutex_stock);
		}
		store.stock = store.stock - val;
		printf("Client %d prend %d du stock, reste %d en stock !\n",
			nb, val, store.stock);
		pthread_mutex_unlock(&store.mutex_stock);
	}
	return NULL;
}

int main (void)
{
	int	i = 0;
	int	ret = 0;

	/* Creation du thread du magasin. */
	printf("Creation du thread du magasin !\n");
	ret = pthread_create(&store.thread_store, NULL, fn_store, NULL);
	if (ret)
	{
		perror(NULL);
		return (errno);
	}

	/* Creation des threads des clients si celui du magasin a reussi. */
	printf("Creation des threads clients !\n");
	for (i = 0; i < NB_CLIENTS; i++)
	{
		ret = pthread_create(&store.thread_clients[i], NULL, fn_clients, &i);
		if (ret)
		{
			perror(NULL);
			return (errno);
		}
	}

	/* Attente de la fin des threads. */
	i = 0;
	for (i = 0; i < NB_CLIENTS; i++)
	{
		pthread_join (store.thread_clients[i], NULL);
	}
	pthread_join (store.thread_store, NULL);

	return EXIT_SUCCESS;
}
