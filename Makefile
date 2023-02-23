# all:
# 	gcc julia_set.c mlx_init.c -lmlx -framework OpenGL -framework AppKit
# #	gcc julia.c -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRCS	= julia_set.c mandelbrot_set.c  mlx_init.c fractol_utils.c events.c
OBJS	= ${SRCS:.c=.o}
NAME	= fractol
HEAD	= includes
# AR		= ar -r
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