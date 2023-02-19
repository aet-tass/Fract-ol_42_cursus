/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:50:08 by aet-tass          #+#    #+#             */
/*   Updated: 2023/02/20 00:15:57 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check_condition(t_mlx *mlx)
{
	mlx->z.re = 0;
	mlx->z.im = 0;
	double	modulus_squared;
	double	scale_factor;
	mlx->max_iter = 50;
	mlx->iter = 0;
	modulus_squared = mlx->z.re * mlx->z.re + mlx->z.im * mlx->z.im;
	while (modulus_squared < 4 && mlx->iter < mlx->max_iter)
	{
		mlx->tmp = mlx->z.re;
		mlx->z.re = mlx->z.re * mlx->z.re - mlx->z.im * mlx->z.im + mlx->c.re;
		mlx->z.im = 2 * mlx->z.im * mlx->tmp + mlx->c.im;
		modulus_squared = mlx->z.re * mlx->z.re + mlx->z.im * mlx->z.im;
		mlx->iter++;		
	}
	return(mlx->iter);	
}

void	mapping_pixels(t_mlx *mlx)
{
	mlx->max_iter = 50;
	double	scale_factor;
	scale_factor = 4.0 / width;
	mlx->win.i = 0;
	mlx->win.j = 0;
	while (mlx->win.i < width)
	{
		while (mlx->win.j < height)
		{
			mlx->c.re = (mlx->win.i - width / 2.0) * scale_factor;
			mlx->c.im	=(mlx->win.j - height / 2.0) * scale_factor;
			mlx->iter = check_condition(mlx); 
			
		mlx->win.j++;
		}
		mlx->win.i++;
	}	
		
	
}

void	mandelbrot_set(t_mlx *mlx)
{
	int i = 0;
	int j = 0;
	while ( i++ < width)
	{
		while (j++ < height)
		{
			mapping_pixels(mlx);
			//check_condition(mlx);	
			
			int	color = mlx->iter % 16 * 0x000000+ mlx->iter % 16 * 0xFFFFFF;
			int	color2 = mlx->iter % 16 * 0xF90000 + mlx->iter % 16 * 0xF2D027 + mlx->iter % 16 * 0xFFFFFF;
			 if (mlx->iter < 10)
		 		draw_fractal(mlx,  j ,  i, color2);
			 else if (mlx->iter < 50)
			 	draw_fractal(mlx,   j , i, color2);
	 		 else
		 	 	draw_fractal(mlx,  j ,  i, 0xFFFFFF);
		}
		//int i++;
	}
	mlx_put_image_to_window(mlx->init_ptr, mlx->window_ptr, mlx->img_ptr, 0, 0);

	//int j++;
}

int	main()
{
	t_mlx mlx;


	mlx.init_ptr = mlx_init();

	mlx.window_ptr = mlx_new_window(mlx.init_ptr, 1000, 1000, "et-tass");

	mlx.img_ptr = mlx_new_image(mlx.init_ptr, 1000, 1000);

	mlx.addr_ptr = mlx_get_data_addr(mlx.img_ptr, &mlx.bit_per_pixel, &mlx.line_lenght, &mlx.endian);

	//draw_fractal(&mlx, width, height, mlx.color);

	//mlx_put_image_to_window(mlx.init, mlx.window_ptr, mlx.img, 0, 0);

	// mlx_pixel_put(init, window, 250, 250, 0x10FF0000);

	// mlx_string_put(init, window, 100, 100, 0xFFFFFFFF, "tass");

	// mlx_key_hook(window, fucntion_handle, &mlx);

	// mlx_mouse_hook(mlx.window, handle, &mlx);

	mandelbrot_set(&mlx);

	mlx_loop(mlx.init_ptr);
}