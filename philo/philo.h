/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:49:54 by hznagui           #+#    #+#             */
/*   Updated: 2023/03/01 09:49:19 by hznagui          ###   ########.fr       */
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
    int a2;
    int a3;
    int a4;
    int a5;
    int arg;
	struct timeval *time;
    struct philo *next;
    
}t_philo;

typedef struct data{
int a1;
int a2;
int a3;
int a4;
int a5;
int arg;
int i;
struct timeval time;
t_philo *p;

} t_data;

int	ft_atoi(const char *str);
t_philo	*ft_lstnew(int index,t_data *a);
void sercular_lst(t_philo **lst);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
#endif
