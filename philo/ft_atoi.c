/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:03:59 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/26 11:06:34 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_return(int c)
{
	if (c == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int c;
	size_t z;
	int i;

	i = 0;
	z = 0;
	c = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\f'
		|| str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			c *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		z = 10 * z + (str[i] - '0');
		if (z > 9223372036854775807)
			return (ft_return(c));
		i++;
	}
	return (z * c);
}