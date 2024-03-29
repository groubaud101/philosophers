/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_master.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:40:28 by groubaud          #+#    #+#             */
/*   Updated: 2022/08/01 11:07:21 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_init_philo(t_master *master)
{
	int	i;
	int	ret;

	i = 0;
	master->philo = (t_philo *)malloc(sizeof(t_philo) * (master->nb_philo));
	if (master->philo == NULL)
		return (1);
	while (i < master->nb_philo)
	{
		if (i == 0)
			master->philo->left_fork = master->nb_philo;
		else
			master->philo->left_fork = i - 1;
		master->philo->right_fork = i;
		ret = pthread_create(master->philo[i].thread_philo, NULL, ft_philo_life, NULL);
		if (ret)
			return (1);
		i++;
	}
	return (0);
}

int	ft_init_master(int ac, char **av, t_master *master)
{
	master->nb_philo = ft_atoi(av[1]);
	master->time_to_die = ft_atoi(av[2]);
	master->time_to_eat = ft_atoi(av[3]);
	master->time_to_sleep = ft_atoi(av[4]);
	master->number_of_eating = -2;
	if (ac == 6)
		master->number_of_eating = ft_atoi(av[5]);
	if (master->nb_philo == -1 || master->time_to_die == -1
		|| master->time_to_eat == -1 || master->time_to_sleep == -1
		|| master->number_of_eating == -1)
		return(ft_print_error("Wrong arguments\n"));
	if (ft_init_philo(master))
		return(ft_print_error("Error \n"));
	return (0);
}