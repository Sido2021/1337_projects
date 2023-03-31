SRCS		= ft_printf.c ft_put_char.c ft_put_string.c ft_print_unsigned_number.c  ft_print_number.c ft_print_number_to_base.c ft_print_hex_number.c ft_print_arg.c ft_print_adress.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

DELCMD		= rm -f

MAKELIB		= ar rcs

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			${MAKELIB} ${NAME} ${OBJS}

%.o:		%.c
			${CC} ${CFLAGS}  -c $< -o $@

clean:
			${DELCMD} ${OBJS} ${BOBJS}

fclean:		clean
			${DELCMD} ${NAME}

re:			fclean all

run:
	gcc main.c ${NAME} && ./a.out
.PHONY: 	all clean fclean re