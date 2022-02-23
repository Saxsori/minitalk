/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:41:51 by aaljaber          #+#    #+#             */
/*   Updated: 2021/12/16 14:46:22 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	getmsg(int sig, siginfo_t *info, void *context)
{
	static int	n;
	static int	bit;
	int			clntpid;

	(void)context;
	clntpid = info->si_pid;
	usleep(50);
	kill(clntpid, SIGUSR2);
	if (sig == SIGUSR1)
		bit += 1 << (7 - n);
	n++;
	if (n == 8)
	{
		ft_putchar_fd(bit, 1);
		n = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = getmsg;
	ft_putstr_fd("PID is: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (42)
		pause();
}
