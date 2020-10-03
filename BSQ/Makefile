NAME	=	BSQ

SRCS	=	${wildcard src/functions/*.c src/main.c}

OBJS	=	${SRCS:.c=.o}

GCC		=	gcc

# CFLAGS	= -Wall -Wextra -Werror
CFLAGS	=	-ggdb -fsanitize=address -fno-omit-frame-pointer -Wall -Wextra -Werror

${NAME}:	${OBJS}
			${GCC} ${CFLAGS} -o ${NAME} ${OBJS} 

all:		${NAME}

clean:
		rm -f ${OBJS}

fclean:		clean
		rm -f ${NAME}

re:			fclean
			all

.PHONY:		clean all fclean re