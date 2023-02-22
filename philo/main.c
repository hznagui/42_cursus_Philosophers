/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:48:16 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/22 15:04:01 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void check(char **argv)
{
	int a;
	int i;
	
	a=1;
	while(argv[a])
	{
		i=0;
		while (argv[a][i])
		{
		if ((argv[a][i] >= 64 && argv[a][i] <= 127) ||
			(argv[a][i] >= 33 && argv[a][i] <= 42) ||
			(argv[a][i] >= '.' && argv[a][i] <= '/') || 
			(argv[a][i] == ',') ||
			(argv[a][i] == '-' && ((argv[a][i + 1] > '9' ||
			argv[a][i + 1] < '0') || (argv[a][i - 1] != '\0' &&
			argv[a][i - 1] != ' '))) || (argv[a][i] == '+' &&
			((argv[a][i + 1] > '9' || argv[a][i + 1] < '0') || 
			(argv[a][i - 1] != '\0' && argv[a][i - 1] != ' '))))
				exit(1);
		i++;
		}
		a++;
	}
}
void check_nothing(char **argv)
{
	int a;
	int i;
	int z;
	
	a = 1;
	while (argv[a])
	{
		z=0;
		i=0;
		while(argv[a][i])
		{
			if (argv[a][i] >= '0' && argv[a][i] <= '9')
				z = 1;
			i++;
		}
		if (z == 0)
		{
			printf("check the arguments \n");
			exit(1);
		}
		a++;
	}
}

int main(int argc, char **argv)
{
    if (argc == 5 || argc == 6)
    {
		check_nothing(argv);
		check(argv);
    }
	else
		exit(1);
}