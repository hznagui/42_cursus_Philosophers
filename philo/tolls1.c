/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolls1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:43:43 by hznagui           #+#    #+#             */
/*   Updated: 2023/03/08 14:29:09 by hznagui          ###   ########.fr       */
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
	int		c;
	size_t	z;
	int		i;

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
//------------------------------------------------------------------------//

int	check(char **argv)
{
	int	a;
	int	i;

	a = 1;
	while (argv[a])
	{
		i = 0;
		while (argv[a][i])
		{
			if ((argv[a][i] >= 58 && argv[a][i] <= 127) ||
				(argv[a][i] >= 33 && argv[a][i] <= 42) ||
				(argv[a][i] >= '.' && argv[a][i] <= '/') ||
				(argv[a][i] == ',') || (argv[a][i] == '+' && ((argv[a][i
								+ 1] > '9' || argv[a][i + 1] < '0')
							|| (argv[a][i - 1] != '\0' && argv[a][i
								- 1] != ' '))))
				return (1);
			i++;
		}
		a++;
	}
	return (0);
}

//------------------------------------------------------------------------//
int	check_nothing(char **argv, int a, int i, int z)
{
	int	k;

	a = 1;
	while (argv[a])
	{
		k = 0;
		z = 0;
		i = 0;
		while (argv[a][i])
		{
			if ((argv[a][i] >= '0' && argv[a][i] <= '9') && z == 0)
			{
				z = 1;
				k += 1;
			}
			else if (!(argv[a][i] >= '0' && argv[a][i] <= '9') && z == 1)
				z = 0;
			i++;
		}
		if (k != 1)
			return (1);
		a++;
	}
	return (0);
}
//------------------------------------------------------------------------//

void	ft_gestion(int a, t_philo *p)
{
	pthread_mutex_lock(&p->m_i);
	if (a == 1 && p->i == 1)
		printf("%ld ms %d has taken a fork\n", ft_time1(p), p->index);
	else if (a == 2 && p->i == 1)
		printf("%ld ms %d is eating\n", ft_time1(p), p->index);
	else if (a == 3 && p->i == 1)
		printf("%ld ms %d is sleeping\n", ft_time1(p), p->index);
	else if (a == 4 && p->i == 1)
		printf("%ld ms %d is thinking\n", ft_time1(p), p->index);
	pthread_mutex_unlock(&p->m_i);
	return ;
}
