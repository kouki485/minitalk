/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 08:24:02 by kkohki            #+#    #+#             */
/*   Updated: 2022/02/16 10:13:22 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(const char *str)
{
	long int	res;
	int			num;

	res = 0;
	num = 1;
	while (('\t' <= *str && *str <= '\r') || (*str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			num *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
		if (res > (long int)INT_MIN * -1 && num == -1)
			return (0);
		if (res > INT_MAX && num == 1)
			return (-1);
	}
	return ((int)res * num);
}

void	send_message(pid_t	pid, char *c)
{
	int	i;
	int	sig_return;

	while (*c)
	{
		i = 0;
		while (i < 8)
		{
			if ((*c >> i) & 1)
				sig_return = kill(pid, SIGUSR1);
			else
				sig_return = kill(pid, SIGUSR2);
			if (sig_return == ERROR)
				ft_puterror("Transmission failure.\n");
			i++;
			usleep(100);
		}
		c++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		ft_puterror("Usage is not correct.\n");
	pid = ft_atoi(argv[1]);
	if (pid < 100 || 99998 < pid)
		ft_puterror("Pid is not correct.\n");
	send_message(pid, argv[2]);
	return (0);
}
