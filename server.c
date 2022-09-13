/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcarval <frcarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 23:10:48 by frcarval          #+#    #+#             */
/*   Updated: 2022/06/06 21:19:15 by frcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_mainstring [8];

char	b2c(void)
{
	int	index[8];
	int	counter;
	int	result;

	index[0] = 128;
	index[1] = 64;
	index[2] = 32;
	index[3] = 16;
	index[4] = 8;
	index[5] = 4;
	index[6] = 2;
	index[7] = 1;
	counter = 0;
	result = 0;
	while (counter <= 7)
	{
		if (g_mainstring[counter] == '1')
			result += index[counter];
		counter++;
	}
	write(1, &result, 1);
	return (result);
}

void	interpreter(int signal)
{
	int	counter;

	counter = 0;
	while (counter < 8)
	{
		if (g_mainstring[counter] != '0' && g_mainstring[counter] != '1')
			break ;
		counter++;
	}
	if (counter == 8)
	{
		b2c();
		counter = 0;
		while (counter < 8)
		{
			g_mainstring[counter] = 0;
			counter++;
		}
		counter = 0;
	}
	if (signal == SIGUSR1)
		g_mainstring[counter] = '0';
	if (signal == SIGUSR2)
		g_mainstring[counter] = '1';
}

int	main(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, interpreter);
	signal(SIGUSR2, interpreter);
	while (1)
	{
		pause();
	}
}
