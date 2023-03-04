/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:49:54 by hznagui           #+#    #+#             */
/*   Updated: 2023/03/04 14:51:47 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct philo
{
	pthread_t		phl;
	pthread_mutex_t	fork;
	int				index;
	int				i;
	long			k;
	long			a1;
	long			a2;
	long			a3;
	long			a4;
	long			a5;
	long			last;
	int				arg;
	struct timeval	*time;
	struct philo	*next;

}					t_philo;

typedef struct data
{
	long			a1;
	long			a2;
	long			a3;
	long			a4;
	long			a5;
	int				arg;
	int				i;
	int				z;
	int				h;
	struct timeval	time;
	pthread_t		death;
	pthread_t		eating;
	t_philo			*p;

}					t_data;

int					ft_atoi(const char *str);
t_philo				*ft_lstnew(int index, t_data *a);
void				sercular_lst(t_philo **lst);
void				ft_lstadd_back(t_philo **lst, t_philo *new);
#endif
