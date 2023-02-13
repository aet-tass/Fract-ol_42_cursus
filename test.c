/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:53:23 by aet-tass          #+#    #+#             */
/*   Updated: 2023/02/13 21:28:31 by goulem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minilibxlinux/mlx.h"

typedef struct s_mlx
{
	void *init;
	void *window;
	void *img;
	char *addr;
	int bit_per_pixel;
	int line_lenght;
	int endian;
}	t_mlx;

/*int fucntion_handle(int key, void *param){
	printf("%d\n", key);
	return (0);
}

int handle(int button, int x, int y, t_mlx *mlx)
{

	mlx_pixel_put(mlx->init, mlx->window, x, y, mlx->color);

	return (0);
}*/

int draw_shape(t_mlx *mlx, int x, int y, int color)
{
	char *addr;

	addr = mlx->addr + (y * mlx->line_lenght + x * (mlx->bit_per_pixel / 8));
	*(unsigned int *)addr = color;
	return (0);
}

int main()
{
	t_mlx mlx;
	

	mlx.init = mlx_init();

	mlx.window = mlx_new_window(mlx.init, 500, 500, "et-tass");
	
	mlx.img = mlx_new_image(mlx.init, 500, 500);

	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bit_per_pixel, &mlx.line_lenght, &mlx.endian);

	draw_shape(&mlx, 100, 100, 0xFFFFFF);

	mlx_put_image_to_window(mlx.init, mlx.window, mlx.img, 0, 0);
	
	// mlx_pixel_put(init, window, 250, 250, 0x10FF0000);

	// mlx_string_put(init, window, 100, 100, 0xFFFFFFFF, "tass");

	// mlx_key_hook(window, fucntion_handle, &mlx);

	// mlx_mouse_hook(mlx.window, handle, &mlx);

	mlx_loop(mlx.init);
}

void    mandelbrot_set.c(double	c_re, double c_img)
{
	int	max_iteration = 50
	double	z_re = 0
7	double	z_img = 0
	int	i = 0
9	modulo = sqrt(pow(z_re, 2) +  pow(z_img, 2));
10     while ( modulo < 2 &&  i < max_iteration)
	{
11         	double	tmp ;
		/*
		 * We store zr in a temporary variable to avoid using the
		 * new value of zr in the z_img calculation
		 */
		tmp = z_re;
12         	z_re = pow(z_re, 2 ) - pow(z_img, 2) + c_re;
13         	z_img = 2*z_img*tmp + c_img;
14         	i++;
	}
}

/*
 * First of all, you should know that the Mandelbrot set is always
 * between -2.1 and 0.6 on the x-axis and between -1.2 and 1.2 on the
 * Ordered
 */

