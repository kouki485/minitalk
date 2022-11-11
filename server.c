/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 06:51:40 by kkohki            #+#    #+#             */
/*   Updated: 2022/02/18 09:50:19 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_signal	g_signal;

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((unsigned char *)b)[i++] = c;
	return (b);
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_signal.ans += (0b100000000 >> g_signal.bit_index);
	if (g_signal.bit_index == 1)
	{
		g_signal.bit_index = 8;
		ft_putchar_fd(g_signal.ans, STDOUT_FILENO);
		g_signal.ans = 0;
		return ;
	}
	g_signal.bit_index--;
}

void	print_pid(void)
{
	ft_putstr_fd("pid:", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

int	main(void)
{
	print_pid();
	g_signal.ans = 0;
	g_signal.bit_index = 8;
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (42)
		pause();
	return (0);
}
