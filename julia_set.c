/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:55:07 by aet-tass          #+#    #+#             */
/*   Updated: 2023/03/08 23:49:17 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_color_julia(t_mlx *mlx)
{
	int	color;

	color = mlx->iter % 4 * 0xFF0000 + mlx->iter % 8 * 0x00FF00 + mlx->iter % 16
		* 0x0000FF;
	draw_fractal(mlx, mlx->win.i, mlx->win.j, color);
}

int	check_condition_julia(t_mlx *mlx)
{
	double	modulus_squared;

	mlx->max_iter = 180;
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

void	mapping_pixels_julia(t_mlx *mlx)
{
	double	scale_factor;

	scale_factor = mlx->zoom / WIDTH;
	mlx->z.re = (mlx->win.i - WIDTH / 2.0) * scale_factor;
	mlx->z.im = (mlx->win.j - HEIGHT / 2.0) * scale_factor;
}

void	julia_set(t_mlx *mlx)
{
	mlx->img_ptr = mlx_new_image(mlx->init_ptr, WIDTH, HEIGHT);
	mlx->addr_ptr = mlx_get_data_addr(mlx->img_ptr, &mlx->bit_per_pixel,
			&mlx->line_lenght, &mlx->endian);
	mlx->max_iter = 50;
	mlx->win.i = 0;
	while (mlx->win.i < WIDTH)
	{
		mlx->win.j = 0;
		while (mlx->win.j < HEIGHT)
		{
			mlx->z.re = 0;
			mlx->z.im = 0;
			mapping_pixels_julia(mlx);
			mlx->iter = check_condition_julia(mlx);
			if (mlx->iter < 15)
				draw_fractal(mlx, mlx->win.i, mlx->win.j, 0x000000);
			else
				get_color_julia(mlx);
			mlx->win.j++;
		}
		mlx->win.i++;
	}
	mlx_put_image_to_window(mlx->init_ptr, mlx->window_ptr, mlx->img_ptr, 0, 0);
}
