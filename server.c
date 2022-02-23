/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:59:00 by aaljaber          #+#    #+#             */
/*   Updated: 2021/12/16 13:59:19 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	getmsg(int sig)
{
	static int	n;
	static int	bits;

	if (sig == SIGUSR1)
		bits += 1 << (7 - n);
	n++;
	if (n == 8)
	{
		ft_putchar_fd(bits, 1);
		n = 0;
		bits = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("PID is: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, getmsg);
	signal(SIGUSR2, getmsg);
	while (42)
		pause();
}
