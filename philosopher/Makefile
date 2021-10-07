SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

UNAME_S = $(shell uname -s)

SRC_PATH = ./src

SRC_NAME =	main.c parsing.c struct.c\
			error.c set_table.c free_struct.c\
			time.c lunch.c philo.c\
			check.c\


OBJS = ${SRCS:.c=.o}

NAME = philo

FLAGS = -Wall -Wextra -Werror

HEADER = -I "./include"

DEBUG = -g -std=c11 -fsanitize=address

CC = clang

RM = rm -f

CD = cd

.c.o:
			${CC} ${FLAGS} ${HEADER} -c $< -o $@

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS} ${FLAGS} -lpthread

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY =	all clean fclean re
