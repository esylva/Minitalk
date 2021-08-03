NAME1 	= client
NAME2 	= server

SRCS1 	= ./client1/client.c
SRCS2 	= ./server1/server.c

OBJS1 	= ${patsubst %.c,%.o,${SRCS1}}
OBJS2 	= ${patsubst %.c,%.o,${SRCS2}}

SRCS1_B = ./client1/client_bonus.c
SRCS2_B = ./server1/server_bonus.c

OBJS1_B = ${SRCS1_B:.c=.o}
OBJS2_B = ${SRCS2_B:.c=.o}

D_F 	= ${patsubst %.c,%.d,${SRCS1} ${SRCS2} ${SRCS1_B} ${SRCS2_B}}

RM 		= @rm -f
CC 		= gcc
CFLAGS 	= -Wall -Werror -Wextra

all: ${NAME1} ${NAME2}

%.o: %.c
		@${CC} ${CFLAGS} -c $< -o $@ -MD

include ${wildcard ${D_F}}

${NAME1}: ${OBJS1}
	${CC} -o ${NAME1} -O2 ${OBJS1}
	@echo 
	@echo ${NAME1} created

${NAME2}: ${OBJS2}
	${CC} -o ${NAME2} -O2 ${OBJS2}
	@echo
	@echo ${NAME2} created

bonus: 
	@make OBJS1="${OBJS1_B}" ${NAME1}
	@make OBJS2="${OBJS2_B}" ${NAME2}
	
rmd:
	${RM} ${D_F}

clean:		
		${RM} ${OBJS1} ${OBJS2} ${OBJS1_B} ${OBJS2_B} ${D_F}
		@echo all *.o and *.d files deleted

fclean:		clean
		${RM} ${NAME1}
		${RM} ${NAME2}
		@echo programs deleted

re:		fclean all

.PHONY:		all clean fclean re bonus