/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 08:23:01 by kkohki            #+#    #+#             */
/*   Updated: 2022/02/16 10:12:25 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# define ERROR -1
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <errno.h>

size_t	ft_strlen(char *str);
void	ft_putstr_fd(char *str, int fd);
int		ft_atoi(const char *str);
void	ft_puterror(char *message);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putnbr_fd(int n, int fd);
int		ft_putchar_fd(int c, char fd);

typedef struct s_signal
{
	pid_t	bit_index;
	pid_t	ans;
}	t_signal;

#endif