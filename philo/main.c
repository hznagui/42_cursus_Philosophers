/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:48:16 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/27 11:59:30 by hznagui          ###   ########.fr       */
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
		k = ft_lstnew(a->i);
		ft_lstadd_back(&a->p,k);
		a->i++;
	}
	sercular_lst(&a->p);
	return(0);
}
void *start(void *l)
{
	t_philo *p = l;
	printf("%d is thinking\n",p->index);
	pthread_mutex_lock(&p->next->fork);
	printf("%d is taking the fork of %d\n",p->index,p->next->index);
	pthread_mutex_lock(&p->fork);
	printf("%d is eating\n",p->index);
		sleep(1);
		
	// usleep(a->a2);
	pthread_mutex_unlock(&p->fork);
	pthread_mutex_lock(&p->next->fork);
	printf("ha howa khrej ll mara  %d\n",p->index);
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
	a->i = 0;
	while (a->i < a->a1)
	{
		if (pthread_join(a->p->phl, NULL))
			return(1);
		a->i++;
	}
	return(0);
}
int values(char **argv, t_data *a,int argc)
{
	a->a1 = ft_atoi(argv[1]);
	a->a2 = ft_atoi(argv[2]);
	a->a3 = ft_atoi(argv[3]);
	a->a4 = ft_atoi(argv[4]);
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
	// a->p = malloc(sizeof(pthread_t)* a->a1);
	// pthread_mutex_init(&a->l,NULL);
	// if (!(a->p))
	// 	return(1);
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
		// while (a.p)
		// {
		// 	printf("%d\n",a.p->index);
		// 	a.p = a.p->next;
		// }
		// pthread_mutex_destroy(&a.l);
	}
	else
		return(1);
}