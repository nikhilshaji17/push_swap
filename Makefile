SRCS = main.c input_parsing/check_input.c node_creation_dupe_check/check_duplicates.c node_creation_dupe_check/node_creation.c sorting/sort_utils.c sorting/sorting_main.c utilities/swap_funcs.c utilities/rot_funcs.c utilities/rev_rot_funcs.c utilities/push_funcs.c utilities/list_utils.c utilities/list_utils_two.c utilities/libft_utils.c utilities/libft_utils_two.c ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_puthex.c ft_printf/ft_putnbr.c ft_printf/ft_putstr.c ft_printf/ft_putunbr.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra -g3

all : ${NAME}

%.o : %.c
	cc ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS}
	cc ${CFLAGS} ${OBJS} -o ${NAME}

clean		:
	rm -f ${OBJS}

fclean		:	clean
	rm -f ${NAME}

re			:	fclean all

.PHONY		:	all clean fclean re