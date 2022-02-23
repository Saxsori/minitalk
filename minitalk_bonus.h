/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:22:00 by aaljaber          #+#    #+#             */
/*   Updated: 2021/12/16 17:22:07 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINITALK_BONUS_H
# 	define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include "./libft/libft.h"

void	getmsg(int sig, siginfo_t *info, void *context);
void	sendmsg(char c, int pid);

#	endif
