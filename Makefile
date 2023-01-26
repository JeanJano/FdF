SRCS		=	fdf.c \
				ft_parsing.c \
				ft_projection.c \
				ft_free.c \
				ft_draw_line.c \
				ft_event.c \
				ft_init.c \
				ft_check_extension.c

NAME		= fdf

OBJS		= ${SRCS:.c=.o}

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra -g

INCLUDES	= -I libft -I mlx

.c.o:
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME):	${OBJS}
			make re -C libft --no-print-directory
			make -C mlx --no-print-directory
			${CC} ${CFLAGS} ${OBJS} -Llibft -lft -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz ${INCLUDES} -o $(NAME)

clean:
			make clean -C libft --no-print-directory
			rm -f ${OBJS}

fclean:		clean
			make fclean -C libft --no-print-directory
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re