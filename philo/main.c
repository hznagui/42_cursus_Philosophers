/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:48:16 by hznagui           #+#    #+#             */
/*   Updated: 2023/03/08 14:28:38 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	continu(t_data *a, int index)
{
	a->h = 0;
	while (a->h < a->a1)
	{
		pthread_mutex_lock(&a->p->m_i);
		a->p->i = 0;
		pthread_detach(a->p->phl);
		pthread_mutex_destroy(&a->p->fork);
		pthread_mutex_destroy(&a->p->m_i);
		pthread_mutex_destroy(&a->p->m_last);
		a->h++;
		a->p = a->p->next;
	}
	if (index == 1)
		printf("%ld ms %d is dead\n", ft_time2(a->p), a->p->index);
	return (0);
}

int	death(void *l)
{
	t_data	*a;

	a = l;
	while (1)
	{
		a->z = 0;
		a->h = 0;
		while (a->h < a->a1)
		{
			pthread_mutex_lock(&a->p->m_last);
			if (a->p->k < a->p->a5)
				a->z = 1;
			if (a->p->last < ft_time2(a->p))
				return (continu(a, 1));
			pthread_mutex_unlock(&a->p->m_last);
			a->h++;
			a->p = a->p->next;
		}
		if (!a->z && a->arg == 6)
			return (continu(a, 0));
	}
}

void	*start(void *l)
{
	t_philo	*p;

	p = l;
	if (!(p->index % 2))
		usleep(500);
	while (1)
	{
		pthread_mutex_lock(&p->fork);
		ft_gestion(1, p);
		pthread_mutex_lock(&p->next->fork);
		ft_gestion(1, p);
		ft_gestion(2, p);
		pthread_mutex_lock(&p->m_last);
		p->last += ft_time1(p);
		p->k += 1;
		pthread_mutex_unlock(&p->m_last);
		ft_pause(1, p);
		pthread_mutex_unlock(&p->fork);
		pthread_mutex_unlock(&p->next->fork);
		ft_gestion(3, p);
		ft_pause(2, p);
		ft_gestion(4, p);
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
	return (death(a));
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
