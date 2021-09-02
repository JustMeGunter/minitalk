/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:51:23 by acrucesp          #+#    #+#             */
/*   Updated: 2021/08/31 22:10:27 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

struct s_char {
	char	c;
	char	i;
};

void	load_char(int b)
{
	static struct s_char bchar = {0, 0};
	if (bchar.i > 7)
	{
		//write(1, &bchar.c, 1);
		printf("%c %i\n", bchar.c, bchar.c);
		bchar.c = 0; 
		bchar.i = 0; 
	}
	if (b == 1)
		bchar.c |= 128 >>  bchar.i;
	bchar.i++;
}

void	sig_handler1(int signum)
{
	(void)signum;
	load_char(1);
	write(1, "1", 1);
}

void	sig_handler2(int signum)
{
	(void)signum;
	load_char(0);
	write(1, "0", 1);
}

int main()
{
	int	pid;
	pid = getpid();
	printf("pid => %i\n", pid);
	signal(SIGUSR1, sig_handler1);
	signal(SIGUSR2, sig_handler2);
	while (1)
		sleep(1);
}
