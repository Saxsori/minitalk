# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaljaber <aaljaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 17:00:26 by aaljaber          #+#    #+#              #
#    Updated: 2021/12/16 14:07:21 by aaljaber         ###   ########.fr        #
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

.c.o:	${CC} ${CFLAGS} -c $< o ${<:.c=.o}

all : 		server client

bonus : serverb clientb

serverb : 
			${MAKE} -C ./libft
			cp ./libft/libft.a ./libft.a
			$(CC) $(CFLAGS) $(SSB) libft.a -o server

clientb : 
			${MAKE} -C ./libft
			cp ./libft/libft.a ./libft.a
			$(CC) $(CFLAGS) $(CSB) libft.a -o client
			
server :
			${MAKE} -C ./libft
			cp ./libft/libft.a ./libft.a
			$(CC) $(CFLAGS) $(SSM) libft.a -o server

client :
			${MAKE} -C ./libft
			cp ./libft/libft.a ./libft.a
			$(CC) $(CFLAGS) $(CSM) libft.a -o client

clean :
		${MAKE} clean -C ./libft
		$(RM) $(SOM) $(COM) ${SOB} ${COB}
		
fclean :	clean
		$(RM) server client libft.a ./libft/libft.a

re : 	fclean  all 

.PHONY: all .c.o clean fclean re 
