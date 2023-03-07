SRCS	= julia_set.c\
		mandelbrot_set.c\
		mlx_init.c\
		fractol_utils.c\
		events.c\
		fractol.c\
		burning_ship_set.c
		
OBJS	= ${SRCS:.c=.o}
NAME	= fractol
HEAD	= includes
CC		= gcc 
CFLAGS	= -Wall -Wextra -Werror
RM 		= rm -f

all:	${NAME}

${NAME}:	${OBJS}
			$(CC) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o  ${NAME} 

clean:
		${RM} ${OBJS} ${BONUS_O}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re