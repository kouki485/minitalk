/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 06:51:44 by kkohki            #+#    #+#             */
/*   Updated: 2022/02/16 08:14:39 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar_fd(int c, char fd)
{
	write(fd, &c, 1);
	return (1);
}

void	ft_putstr_fd(char *str, int fd)
{
	ssize_t	i;

	if (!str)
		return ;
	i = write(fd, str, ft_strlen(str));
	if (i == -1)
		return ;
}

void	ft_puterror(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd('0' + (num % 10), fd);
}
