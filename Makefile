# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 17:00:26 by aaljaber          #+#    #+#              #
#    Updated: 2022/08/09 14:20:02 by aaljaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SSM = ./SRC/Mandatory/server.c

CSM = ./SRC/Mandatory/client.c 

SSB = ./SRC/Bonus/server_bonus.c

CSB = ./SRC/Mandatory/client_bonus.c

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
			${MAKE} -C ./LIB/libft
			$(CC) $(CFLAGS) $(SSB) ./LIB/libft/libft.a -o server

clientb : 
			${MAKE} -C ./LIB/libft
			$(CC) $(CFLAGS) $(CSB) ./LIB/libft/libft.a -o client
			
server :
			${MAKE} -C ./LIB/libft
			$(CC) $(CFLAGS) $(SSM) ./LIB/libft/libft.a -o server

client :
			${MAKE} -C ./LIB/libft
			$(CC) $(CFLAGS) $(CSM) ./LIB/libft/libft.a -o client

clean :
		${MAKE} clean -C ./LIB/libft
		$(RM) $(SOM) $(COM) ${SOB} ${COB}
		
fclean :	clean
		$(RM) server client ./LIB/libft/libft.a

re : 	fclean  all 

