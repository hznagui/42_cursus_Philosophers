/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:48:16 by hznagui           #+#    #+#             */
/*   Updated: 2023/03/03 17:54:42 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
				(argv[a][i] == ',') || (argv[a][i] == '+' && ((argv[a][i + 1] > '9' || argv[a][i
				+ 1] < '0') || (argv[a][i - 1] != '\0'
				&& argv[a][i - 1] != ' '))))
				return(1);
			i++;
		}
		a++;
	}
	return (0);
}
int	check_nothing(char **argv)
{
	int	a;
	int	i;
	int	z;
	int	k;

	a = 1;
	while (argv[a])
	{
		k = 0;
		z = 0;
		i = 0;
		while (argv[a][i])
		{
			if ((argv[a][i] >= '0' && argv[a][i] <= '9' ) && z == 0)
			{
				z = 1;
				k += 1;	
			}
			else if (!(argv[a][i] >= '0' && argv[a][i] <= '9' ) && z == 1)
			{
				z = 0;
				// k += 1;	
			}
			i++;
			// printf("%d\n",k);
		}
		if (k != 1)
		{
			write(2,"check the arguments \n",22);
			return(1);
		}
		a++;
	}
	return(0);
}
int  create_struct(t_data *a)
{
	t_philo *k;
	
	a->i=1;
	while (a->i <= a->a1)
	{
		k = ft_lstnew(a->i,a);
		ft_lstadd_back(&a->p,k);
		a->i++;
	}
	sercular_lst(&a->p);
	return(0);
}
long long ft_gestion(int a,struct timeval *time1,t_philo *p)
{
	long long o;

	gettimeofday(time1,NULL);
	o = (time1->tv_sec - p->time->tv_sec) * 1000 + (time1->tv_usec - p->time->tv_usec) / 1000;
	if (a == 1)
    	printf("%lld ms %d has taken a fork\n", o ,p->index);
	else if (a == 2)
    	printf("%lld ms %d is eating\n", o, p->index);
	else if (a == 3)
    	printf("%lld ms %d is sleeping\n",o, p->index);
	else if (a == 4)
    	printf("%lld ms %d is thinking\n",o, p->index);
	else if (a == 5)
    	printf("%lld ms %d is dead\n",o, p->index);
	return (o);
}

void *routine(void *l)
{
	struct timeval time1;
	t_data *a = l;
	while (1)
	{
		if (a->p->last < ft_gestion(0,&time1,a->p))
		{
			ft_gestion(5,&time1,a->p);
			return(0);
		}
		a->p = a->p->next;
	}
}
void ft_pause(int index,struct timeval *time1,t_philo *p)
{
	long long k;
	if (index == 1)
	{
		k = ft_gestion(0,time1,p)+p->a3;
		while (ft_gestion(0,time1,p) < k)
			usleep(100);
	}
	else if (index == 2)
	{
		k = ft_gestion(0,time1,p)+p->a4;
		while (ft_gestion(0,time1,p) < k)
			usleep(100);
	}
}
void *start(void *l)
{
	t_philo *p = l;
	struct timeval time1;

	if (!(p->index % 2))
			usleep(200);
	while (1)
	{
    	pthread_mutex_lock(&p->fork);
		ft_gestion(1,&time1,p);
		pthread_mutex_lock(&p->next->fork);
		ft_gestion(2,&time1,p);
		ft_pause(1,&time1,p);
		p->last += ft_gestion(0,&time1,p);
    	pthread_mutex_unlock(&p->fork);
    	pthread_mutex_unlock(&p->next->fork);
		ft_gestion(3,&time1,p);
		ft_pause(2,&time1,p);
		ft_gestion(4,&time1,p);
	}
	return(0);
}
int create_threads(t_data *a)
{
	a->i = 0;
	while (a->i < a->a1)
	{
		if (pthread_create(&a->p->phl, NULL,start,a->p))
			return(1);
		a->i++;
		a->p = a->p->next;
	}
	if (pthread_create(&a->death, NULL,routine,a))
			return(1);
	if (pthread_join(a->death,NULL))
			return(1);
	return(0);
}
int values(char **argv, t_data *a,int argc)
{
	a->a1 = ft_atoi(argv[1]);
	a->a2 = ft_atoi(argv[2]);
	a->a3 = ft_atoi(argv[3]);
	a->a4 = ft_atoi(argv[4]);
	a->arg = argc;
	if (argc == 6)
	{
		a->a5 = ft_atoi(argv[5]);
		if (a->a1 <= 0||a->a2 <= 0||a->a3 <= 0||a->a4 <= 0||a->a5 <= 0)
			{
				write(2,"some number are not logical \n",30);
				return(1);
			} 
	}
	else if (a->a1 <= 0||a->a2 <= 0||a->a3 <= 0||a->a4 <= 0)
			{
				write(2,"some number are not logical \n",30);
			return(1);
			}
	
	create_struct(a);
	gettimeofday(&(a->time),NULL);;
	return (0);
}
int	main(int argc, char **argv)
{
	t_data a;
	if (argc == 5 || argc == 6)
	{
		
		if (check_nothing(argv) || check(argv) || values(argv,&a,argc))
			return(1);
		create_threads(&a);
		return(0);
	}
	else
		return(1);
}