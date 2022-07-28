/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:06:10 by groubaud          #+#    #+#             */
/*   Updated: 2022/07/28 13:49:56 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

// number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

typedef struct	s_philo
{
	int			num_philo;
	pthread_t	thread_fork;
	pthread_t	thread_philo;
	pthread_cond_t	free_fork;
	
}t_philo;

typedef struct s_master
{
	int		nb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_eating;
	t_philo	*philo;
}t_master;

/* ft_lib.c */
int	ft_strlen(char *str);
int	ft_atoi(char *nbr);

/* ft_error.c */
int	ft_print_error(char *str);

/* ft_init_master.c */
int	ft_init_master(int ac, char **av, t_master *master);


#endif