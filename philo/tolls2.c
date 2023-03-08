/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolls2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:55:00 by hznagui           #+#    #+#             */
/*   Updated: 2023/03/08 11:21:07 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_pause(int index, t_philo *p)
{
	long	k;

	if (index == 1)
	{
		k = ft_time1(p) + p->a3;
		while (ft_time1(p) < k)
			usleep(100);
	}
	else if (index == 2)
	{
		k = ft_time1(p) + p->a4;
		while (ft_time1(p) < k)
			usleep(100);
	}
}
//------------------------------------------------------------------------//

int	values(char **argv, t_data *a, int argc)
{
	a->a1 = ft_atoi(argv[1]);
	a->a2 = ft_atoi(argv[2]);
	a->a3 = ft_atoi(argv[3]);
	a->a4 = ft_atoi(argv[4]);
	a->arg = argc;
	if (argc == 6)
	{
		a->a5 = ft_atoi(argv[5]);
		if (a->a1 <= 0 || a->a2 <= 0 || a->a3 <= 0 || a->a4 <= 0 || a->a5 <= 0)
		{
			write(2, "some number are not logical \n", 30);
			return (1);
		}
	}
	else if (a->a1 <= 0 || a->a2 <= 0 || a->a3 <= 0 || a->a4 <= 0)
	{
		write(2, "some number are not logical \n", 30);
		return (1);
	}
	create_struct(a);
	gettimeofday(&(a->time), NULL);
	return (0);
}
