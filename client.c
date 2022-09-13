/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcarval <frcarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 23:08:58 by frcarval          #+#    #+#             */
/*   Updated: 2022/06/06 21:07:12 by frcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(int call)
{
	if (call == 1)
		write(1, "Error, Invalid Parameters!", 26);
	exit(EXIT_SUCCESS);
}

void	send_bin(int chr, int pid)
{
	int		control;
	int		counter;

	control = 128;
	counter = 0;
	while (counter < 8)
	{
		if (chr < control)
		{
			kill(pid, SIGUSR1);
			usleep(80);
		}
		else
		{
			chr -= control;
			kill(pid, SIGUSR2);
			usleep(80);
		}
		counter++;
		control /= 2;
	}
}

int	main(int argc, char **argv)
{
	int	counter;
	int	pid;

	if (argc != 3)
		error(1);
	counter = 0;
	pid = atoi(argv[1]);
	while (argv[2][counter])
	{
		send_bin((int) argv[2][counter], pid);
		counter++;
	}
	send_bin(0, pid);
}
