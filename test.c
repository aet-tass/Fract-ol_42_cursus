/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:53:23 by aet-tass          #+#    #+#             */
/*   Updated: 2023/02/14 01:10:40 by aet-tass         ###   ########.fr       */
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

/*int draw_shape(t_mlx *mlx, int x, int y, int color)
{
	char *addr;

	addr = mlx->addr + (y * mlx->line_lenght + x * (mlx->bit_per_pixel / 8));
	*(unsigned int *)addr = color;
	return (0);
}*/

void    mandelbrot(t_mlx *mlx)
{
	int	max_iteration = 255;
	double	z_re = 0;
	double	z_img = 0;
	double	c_re = 0;
	double	c_img = 0;
	int	i = 0;
	int x = 0;
	int y = 0;
	double modulo ;
	 

	while (x < 1000)
	{
		y = 0;
		while (y < 1000)
		{
			z_re = 0;
			z_img = 0;
			c_re = (x - 1000 / 2.0) * (4.0 / 1000);
			c_img = (y - 1000 / 2.0) * (4.0 / 1000);
			i = 0;
			//modulo = sqrt(pow(z_re, 2) + pow(z_img, 2));
			modulo = z_re * z_re + z_img * z_img;
     		while ( modulo < 4 &&  i < max_iteration)
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
				modulo = z_re * z_re + z_img * z_img;
         		i++;
			}
	 		if (i < 10)
		 		mlx_pixel_put(mlx->init, mlx->window, x, y, 0xFFFFFF);
			else if (i < 100)
				mlx_pixel_put(mlx->init, mlx->window, x, y, 0xFF0000);
	 		else
		 		mlx_pixel_put(mlx->init, mlx->window, x, y, 0x000000);
			y++;
		}
	 	x++;
	}
}

int main()
{
	t_mlx mlx;
	

	mlx.init = mlx_init();

	mlx.window = mlx_new_window(mlx.init, 1000, 1000, "et-tass");
	
	//mlx.img = mlx_new_image(mlx.init, 500, 500);

	//mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bit_per_pixel, &mlx.line_lenght, &mlx.endian);

	//draw_shape(&mlx, 100, 100, 0xFFFFFF);

	//mlx_put_image_to_window(mlx.init, mlx.window, mlx.img, 0, 0);
	
	// mlx_pixel_put(init, window, 250, 250, 0x10FF0000);

	// mlx_string_put(init, window, 100, 100, 0xFFFFFFFF, "tass");

	// mlx_key_hook(window, fucntion_handle, &mlx);

	// mlx_mouse_hook(mlx.window, handle, &mlx);
	
	mandelbrot(&mlx);

	mlx_loop(mlx.init);
}

/*
 * First of all, you should know that the Mandelbrot set is always
 * between -2.1 and 0.6 on the x-axis and between -1.2 and 1.2 on the
 * Ordered
 */
