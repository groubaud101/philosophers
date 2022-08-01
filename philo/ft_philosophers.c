/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:29:35 by groubaud          #+#    #+#             */
/*   Updated: 2022/08/01 11:06:10 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"



int	main(int ac, char **av)
{
	t_master	master;
	int			i;

	if (ac < 5 || ac > 6)
		return (ft_print_error("Wrong number of argument\n"));
	if (ft_init_master(ac, av, &master))
		return (1);
	i = master.number_of_eating;
	while (i != 0)
	{
		if (i < 0)
			i = -1;
		usleep(100);


		i--;
	}

	return (0);
}