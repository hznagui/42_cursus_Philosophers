/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:41:11 by hznagui           #+#    #+#             */
/*   Updated: 2023/03/04 11:01:38 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(int index,t_data *a)
{
	t_philo	*p;

	p = malloc (sizeof(t_philo));
	if (!p)
		return (0);
    p->a2 = a->a2;
    p->a1 = a->a1;
	p->a3 = a->a3;
	p->a4 = a->a4;
	p->arg = a->arg;
	p->time = &a->time;
	p->last = a->a2;
	p->i = 1;
	p->k = 0;
	
	
	if (p->arg == 6)
		p->a5 = a->a5;
	p -> next = NULL;
	pthread_mutex_init(&p->fork,NULL) ;
	p -> index = index;
	return (p);
}
void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*p;

	if (!lst || !new)
		return ;
	else if (*lst == 0)
		*lst = new;
	else
	{
		p = *lst;
		while (p -> next)
		{
			p = p -> next;
		}
		p -> next = new ;
	}
}
void sercular_lst(t_philo **lst)
{
	t_philo *p;
	p = *lst;
	while (p->next)
		p=p->next;
	p->next = *lst;
}