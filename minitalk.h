/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:22:25 by aaljaber          #+#    #+#             */
/*   Updated: 2021/12/16 17:22:28 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINITALK_H
# 	define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include "./libft/libft.h"

void	getmsg(int sig);
void	sendmsg(char c, int pid);

#	endif
