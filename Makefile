all:
#	gcc julia.c -lmlx -framework OpenGL -framework AppKit
	gcc julia.c -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
