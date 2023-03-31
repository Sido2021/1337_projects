SRCS		= ft_putchr.c ft_putstr.c pa.c pb.c pop.c push.c ra.c rb.c reverse_rotate.c\
				rotate.c rr.c rra.c rrb.c rrr.c sa.c sb.c ss.c swap.c main.c helper_functions/print_stack.c \
				helper_functions/stack_contains_num.c get_smallest_number.c stack_dup.c num_dup.c \
				load_best_sorted_list.c helper_functions/print_stack_by_group.c sort_stack.c
OBJS		= ${SRCS:.c=.o}

NAME		= push_swap

DELCMD		= rm -f

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o:		%.c
			${CC} ${CFLAGS}  -c $< -o $@

clean:
			${DELCMD} ${OBJS}

fclean:		clean
			${DELCMD} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean

run:		re
			${DELCMD} ${OBJS} && ./push_swap