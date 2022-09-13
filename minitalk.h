/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcarval <frcarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:58:04 by frcarval          #+#    #+#             */
/*   Updated: 2022/06/06 21:06:39 by frcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

//Client
void	error(int call);
void	send_bin(int chr, int pid);
//Server
void	interpreter(int signal);
void	printer(char	*bin);
char	b2c(void);
//Side Functions
char	*my_dup(char	*string);
int		my_len(char *string);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char *str, int fd);

#endif