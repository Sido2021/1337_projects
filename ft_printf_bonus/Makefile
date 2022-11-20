_SRCS		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
LIBFTDIR	= ./libft
SRCS		= $(patsubst %,$(LIBFTDIR)/%,$(_SRCS)) ft_printf.c ft_put_char.c ft_put_nchar.c ft_print_arg.c \
			ft_put_char_presu.c ft_put_string.c ft_get_number.c ft_fill_number_base.c ft_get_base_number_len.c \
			ft_get_adress.c ft_get_hex_number.c ft_flags_contain.c ft_get_flag_count.c ft_reset_flag.c \
			ft_get_flag_index.c ft_clean_flags.c ft_get_number_and_load_steps.c ft_malloc_plus.c ft_calculate_zeros.c
			
OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

DELCMD		= rm -f

MAKELIB		= ar -rcs

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			${MAKELIB} ${NAME} ${OBJS}

%.o:		%.c
			${CC} ${CFLAGS}  -c $< -o $@

run:		
			${CC} main.c ${NAME} && ./a.out
clean:
			${DELCMD} ${OBJS} ${BOBJS}

fclean:		clean
			${DELCMD} ${NAME}

bonus:		all

re:			fclean all

.PHONY: 	all clean fclean re bonus
