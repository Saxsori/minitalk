/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:47:32 by aaljaber          #+#    #+#             */
/*   Updated: 2021/12/16 17:03:31 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_bit;

void	sendmsg(char c, int pid)
{
	int	a;

	a = 7;
	while (a >= 0)
	{
		if (c >> a & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
		a--;
	}
}

void	confirm(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	usleep(50);
	if (sig == SIGUSR2)
	{
		g_bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t				servpid;
	int					i;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = confirm;
	i = 0;
	servpid = ft_atoi(argv[1]);
	sigaction(SIGUSR2, &sa, 0);
	if (argc == 3)
	{
		while (argv[2][i] != '\0')
			sendmsg(argv[2][i++], servpid);
		ft_putstr_fd("---SENT---\n", 1);
		ft_putnbr_fd(g_bit, 1);
		exit(0);
	}
	else
		exit(1);
	return (0);
}
