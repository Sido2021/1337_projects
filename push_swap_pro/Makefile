SRCS		= ft_putchr.c ft_putstr.c pa.c pb.c pop.c push.c ra.c rb.c reverse_rotate.c\
				rotate.c rr.c rra.c rrb.c rrr.c sa.c sb.c ss.c swap.c main.c helper_functions/print_stack.c \
				helper_functions/stack_contains_num.c  helper_functions/print_stack_by_group.c \
				sort_stack.c num_dup.c stack_dup.c load_best_sorted_list.c
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


NUMS10	= 33 34 11 41 35 15 2 23 22 37

NUMS50	= 31 186 16 153 101 117 159 166 195 103 151 160 4 168 2 29 183 91 150 37 175 106 111 17 28 47 184 179 177 97 10 164 52 69 36 163 64 15 125 142 65 140 189 152 83 110 70 93 19 56

NUMS100	= 612 485 367 416 654 355 459 179 72 395 666 79 704 846 373 651 491 852 41 993 957 988 120 952 697 322 886 508 405 251 591 722 85 228 643 245 920 477 198 549 689 277 23 377 597 706 129 201 883 522 503 671 565 662 1 223 239 647 921 215 922 674 538 989 600 214 845 919 529 170 850 771 675 157 283 517 684 937 293 495 95 340 534 16 272 112 358 980 452 364 300 162 731 543 420 577 122 799 325 66

n10:
	@./push_swap ${NUMS10}
n50:
	@./push_swap ${NUMS50}
n100:
	@./push_swap ${NUMS100}


