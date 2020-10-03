SRCS	=	main_rush02.c btree_insert_and_search.c get_number_str.c mini_func.c parse_dict.c print_number_main.c ft_trimdict.c ft_checknumber.c ft_strmall.c btree_apply_prefix.c

OBJS	= ${SRCS:.c=.o}
NAME	= rush-02
CC 		= gcc
RM		= rm -f
INC_DIR = includes

CFLAGS	= -Wall -Wextra -Werror -I ${INC_DIR}
OFLAGS	= -Wall -Wextra -Werror

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		 	@${CC} ${OFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}
			
clean:		
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re