/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcarval <frcarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:42:07 by frcarval          #+#    #+#             */
/*   Updated: 2022/06/06 21:09:38 by frcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*my_dup(char	*string)
{
	char	*returner;
	int		counter;

	counter = 0;
	if (!string)
		returner = malloc(sizeof(char));
	else
	{
		returner = malloc(sizeof(char) * (my_len(string) + 1));
		while (string[counter])
		{
			returner[counter] = string[counter];
			counter++;
		}
	}
	returner[counter] = '\0';
	return (returner);
}
