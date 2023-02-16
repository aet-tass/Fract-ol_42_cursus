/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:53:23 by aet-tass          #+#    #+#             */
/*   Updated: 2023/02/16 18:49:50 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <math.h>

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

int draw_fractal(t_mlx *mlx, int width, int height, int color)
{
	char *addr;

	addr = mlx->addr + (height * mlx->line_lenght + width * (mlx->bit_per_pixel / 8));
	*(unsigned int *)addr = color;
	return (0);
}

void    mandelbrot_set(t_mlx *mlx)
{
	int	max_iteration = 50;
	double	z_re = 0;
	double	z_img = 0;
	double	c_re = 0;
	double	c_img = 0;
	int	i = 0;
	int y = 0, x = 0;
	double sqrt_modulus ;
	double	scale_factor;
	double	height = 1000;
	double	width = 1000;
	int	color;

	while (x < width)
	{
		y = 0;
		while (y < height)
		{

			z_re = 0;
			z_img = 0;
			scale_factor = 4.0/ width;
			c_re = (x - width / 2.0) * scale_factor;
			c_img = (y - height / 2.0) * scale_factor;
			i = 0;
			//modulo = sqrt(pow(z_re, 2) + pow(z_img, 2));
			sqrt_modulus = z_re * z_re + z_img * z_img;
     		while ( sqrt_modulus < 4 &&  i < max_iteration)
			{
         		double	tmp ;
				tmp = z_re;
				/*
		 		* We store zr in a temporary variable to avoid using the
		 		* new value of zr in the z_img calculation
				*/
        	 	z_re = z_re * z_re - z_img * z_img + c_re;
         		z_img = 2 * z_img * tmp + c_img;
				//modulo  = sqrt(pow(z_re, 2) + pow(z_img, 2));	
				sqrt_modulus = z_re * z_re + z_img * z_img;
         		i++;
			}
			int	color = i % 16 * 0x000000+ i % 16 * 0xFFFFFF;
			int	color2 = i % 16 * 0xF90000 + i % 16 * 0xF2D027;
			if (i < 17)
		 		draw_fractal(mlx, x ,  y, color);
			else if (i < 50)
				draw_fractal(mlx,  x , y, color2);
	 		else
		 		draw_fractal(mlx, x , y, 0x000000);

			y++;
		}
	 	x++;
	}
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->img, 0, 0);
	mlx_loop(mlx->init);
}

int main()
{
	t_mlx mlx;
	

	mlx.init = mlx_init();

	mlx.window = mlx_new_window(mlx.init, 1000, 1000, "et-tass");
	
	mlx.img = mlx_new_image(mlx.init, 1000, 1000);

	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bit_per_pixel, &mlx.line_lenght, &mlx.endian);

	//draw_fractal(&mlx, width, height, mlx.color);

	//mlx_put_image_to_window(mlx.init, mlx.window, mlx.img, 0, 0);
	
	// mlx_pixel_put(init, window, 250, 250, 0x10FF0000);

	// mlx_string_put(init, window, 100, 100, 0xFFFFFFFF, "tass");

	// mlx_key_hook(window, fucntion_handle, &mlx);

	// mlx_mouse_hook(mlx.window, handle, &mlx);
	
	mandelbrot_set(&mlx);

	mlx_loop(mlx.init);
}

/*
 * First of all, you should know that the Mandelbrot set is always
 * between -2.1 and 0.6 on the x-axis and between -1.2 and 1.2 on the
 * Ordered
 */


