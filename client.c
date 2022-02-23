/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:31:51 by aaljaber          #+#    #+#             */
/*   Updated: 2021/11/13 17:05:17 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(100);
		a--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	pid = ft_atoi(argv[1]);
	if (argc == 3)
	{
		while (argv[2][i] != '\0')
			sendmsg(argv[2][i++], pid);
		exit(0);
	}
	else
		exit(1);
	return (0);
}
