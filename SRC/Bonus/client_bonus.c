/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:47:32 by aaljaber          #+#    #+#             */
/*   Updated: 2022/08/09 15:14:28 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/minitalk_bonus.h"

int	g_bit;

void	sendmsg(char c, int pid)
{
	int	a;
	int k;

	a = 7;
	while (a >= 0)
	{
		if (c >> a & 1)
		{
			k = kill(pid, SIGUSR1);
			if (k != 0)
				exit(1);
		}
		else
		{
			k = kill(pid, SIGUSR2);
			if (k != 0)
				exit(1);
		}
		pause();
		a--;
	}
}

void	confirm(int sig)
{
	(void)sig;
	usleep(50);
	g_bit++;
}

int	main(int argc, char **argv)
{
	pid_t				servpid;
	int					i;

	i = 0;
	signal(SIGUSR2, confirm);
	if (argc == 3)
	{
		servpid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
			sendmsg(argv[2][i++], servpid);
		ft_putstr_fd("---SENT---\n", 1);
		ft_putnbr_fd(g_bit, 1);
		ft_putstr_fd("\n", 1);
		exit(0);
	}
	else
		exit(1);
	return (0);
}
