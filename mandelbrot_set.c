/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:50:08 by aet-tass          #+#    #+#             */
/*   Updated: 2023/03/08 23:12:37 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_condition_mandelbrot(t_mlx *mlx)
{
	double	modulus_squared;

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
	return (mlx->iter);
}

void	mapping_pixels_mandelbrot(t_mlx *mlx)
{
	mlx->scale_factor = mlx->zoom / WIDTH;
	mlx->c.re = (mlx->win.i - WIDTH / 2.0) * mlx->scale_factor;
	mlx->c.im = (mlx->win.j - HEIGHT / 2.0) * mlx->scale_factor;
}

void	mandelbrot_set(t_mlx *mlx)
{
	mlx->img_ptr = mlx_new_image(mlx->init_ptr, WIDTH, HEIGHT);
	mlx->addr_ptr = mlx_get_data_addr(mlx->img_ptr, &mlx->bit_per_pixel,
			&mlx->line_lenght, &mlx->endian);
	mlx->z.re = 0;
	mlx->z.im = 0;
	mlx->max_iter = 50;
	mlx->win.i = 0;
	while (mlx->win.i < WIDTH)
	{
		mlx->win.j = 0;
		while (mlx->win.j < HEIGHT)
		{
			mlx->z.re = 0;
			mlx->z.im = 0;
			mapping_pixels_mandelbrot(mlx);
			mlx->iter = check_condition_mandelbrot(mlx);
			if (mlx->iter < 11)
				draw_fractal(mlx, mlx->win.i, mlx->win.j, 0xf48c06);
			else
				coloring(mlx);
			mlx->win.j++;
		}
		mlx->win.i++;
	}
	mlx_put_image_to_window(mlx->init_ptr, mlx->window_ptr, mlx->img_ptr, 0, 0);
}
