all:
	gcc julia_set.c mlx_utils.c -lmlx -framework OpenGL -framework AppKit
#	gcc mandelbrot_set.c -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
