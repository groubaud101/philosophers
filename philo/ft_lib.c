/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:16:51 by groubaud          #+#    #+#             */
/*   Updated: 2022/07/28 12:38:21 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int	ft_check_nbr(char *nbr)
{
	int	i;

	i = 0;
	if (!nbr)
		return (-1);
	while (nbr[i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *nbr)
{
	int	nb;
	int	i;
	int	mult;

	if (ft_check_nbr(nbr))
		return (-1);
	i = ft_strlen(nbr) - 1;
	nb = 0;
	mult = 1;
	while (i >= 0)
	{
		nb = nb + ((nbr[i] - '0') * mult);
		mult *= 10;
		i--;
	}
	return (nb);
}