/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:48:16 by hznagui           #+#    #+#             */
/*   Updated: 2023/03/04 18:07:12 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*continu(t_data *a, struct timeval *time1, int index)
{
	a->h = 0;
	while (a->h < a->a1)
	{
		a->p->i = 0;
		a->h++;
		pthread_detach(a->p->phl);
		a->p = a->p->next;
	}
	a->i = -1;
	if (index == 1)
		ft_gestion(5, time1, a->p);
	return (0);
}

void	*death(void *l)
{
	struct timeval	time1;
	t_data			*a;

	a = l;
	while (1)
	{
		a->z = 0;
		a->h = 0;
		while (a->h < a->a1)
		{
			if (a->p->k < a->p->a5)
				a->z = 1;
			if (a->p->last < ft_gestion(0, &time1, a->p))
				return (continu(a, &time1, 1));
			a->h++;
			a->p = a->p->next;
		}
		if (!a->z && a->arg == 6)
			return (continu(a, &time1, 0));
	}
}

void	*start(void *l)
{
	t_philo			*p;
	struct timeval	time1;

	p = l;
	if (!(p->index % 2))
		usleep(500);
	while (1)
	{
		pthread_mutex_lock(&p->fork);
		ft_gestion(1, &time1, p);
		pthread_mutex_lock(&p->next->fork);
		ft_gestion(1, &time1, p);
		ft_gestion(2, &time1, p);
		ft_pause(1, &time1, p);
		p->last += ft_gestion(0, &time1, p);
		p->k += 1;
		pthread_mutex_unlock(&p->fork);
		pthread_mutex_unlock(&p->next->fork);
		ft_gestion(3, &time1, p);
		ft_pause(2, &time1, p);
		ft_gestion(4, &time1, p);
	}
	return (0);
}

int	create_threads(t_data *a)
{
	a->i = 0;
	while (a->i < a->a1)
	{
		if (pthread_create(&a->p->phl, NULL, start, a->p))
			return (1);
		a->i++;
		a->p = a->p->next;
	}
	if (pthread_create(&a->death, NULL, death, a))
		return (1);
	while (1)
	{
		if (a->i == -1)
		{
			pthread_detach(a->death);
			return (0);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	a;

	if (argc == 5 || argc == 6)
	{
		if (check_nothing(argv, 0, 0, 0) || check(argv) || values(argv, &a,
				argc))
			return (1);
		create_threads(&a);
		return (0);
	}
	else
		return (1);
}
