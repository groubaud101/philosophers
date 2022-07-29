/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:29:35 by groubaud          #+#    #+#             */
/*   Updated: 2022/07/28 14:13:17 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"



int	main(int ac, char **av)
{
	t_master	master;

	if (ac < 5 || ac > 6)
		return (ft_print_error("Wrong number of argument\n"));
	if (ft_init_master(ac, av, &master))
		return (1);

	return (0);
}