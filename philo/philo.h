/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:49:54 by hznagui           #+#    #+#             */
/*   Updated: 2023/03/03 15:48:15 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct philo
{
    pthread_t phl;
    pthread_mutex_t fork;
    int index;
    long long a2;
    long long a3;
    long long a4;
    long long a5;
    long long last;
    int arg;
	struct timeval *time;
    struct philo *next;
    
}t_philo;

typedef struct data{
long long a1;
long long a2;
long long a3;
long long a4;
long long a5;
int arg;
int i;
struct timeval time;
pthread_t death;
t_philo *p;

} t_data;

int	ft_atoi(const char *str);
t_philo	*ft_lstnew(int index,t_data *a);
void sercular_lst(t_philo **lst);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
#endif
