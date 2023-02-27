/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:41:11 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/27 11:07:16 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(int index)
{
	t_philo	*p;

	p = malloc (sizeof(t_philo));
	if (!p)
		return (0);
	p -> next = NULL;
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