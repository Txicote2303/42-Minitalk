/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcarval <frcarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:38:26 by frcarval          #+#    #+#             */
/*   Updated: 2022/06/06 21:10:10 by frcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	my_len(char	*string)
{
	int	counter;

	counter = 0;
	while (string[counter])
		counter++;
	return (counter);
}
