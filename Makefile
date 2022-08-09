# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrar <abrar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 17:00:26 by aaljaber          #+#    #+#              #
#    Updated: 2022/05/01 08:00:24 by abrar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SSM	= server.c

CSM = client.c 

SSB = server_bonus.c

CSB = client_bonus.c

SOM		= $(SSM:.c=.o)
COM		= $(CSM:.c=.o)

SOB		= $(SSB:.c=.o)
COB		= $(CSB:.c=.o)

RM			= rm -f
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all : 		server client

bonus : serverb clientb

serverb : 
			${MAKE} -C ./libft
			$(CC) $(CFLAGS) $(SSB) ./libft/libft.a -o server

clientb : 
			${MAKE} -C ./libft
			$(CC) $(CFLAGS) $(CSB) ./libft/libft.a -o client
			
server :
			${MAKE} -C ./libft
			$(CC) $(CFLAGS) $(SSM) ./libft/libft.a -o server

client :
			${MAKE} -C ./libft
			$(CC) $(CFLAGS) $(CSM) ./libft/libft.a -o client

clean :
		${MAKE} clean -C ./libft
		$(RM) $(SOM) $(COM) ${SOB} ${COB}
		
fclean :	clean
		$(RM) server client ./libft/libft.a

re : 	fclean  all 

.PHONY: all .c.o clean fclean re 
