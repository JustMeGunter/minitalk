/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:36:54 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/31 20:51:06 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int pid;
	int i;
	int k;

	if (argc < 3)
	{
		printf("exit");
		exit(0);
	}
	i = 8;
	k = 0;
	pid = atoi(argv[1]);
	while (argv[2][k] != 0)
	{
		printf("c :%c\n", *argv[2]);
		while (--i >= 0)
		{
			if (*argv[2] & (1 << i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(500);
		}
		i = 8;
		k++;
	}
	//bonus
	printf("%i\n", i);
	while (--i >= 0)
	{
		kill(pid, SIGUSR2);
		usleep(500);
	}
	printf("%i\n", getpid());
}
