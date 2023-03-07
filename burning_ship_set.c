/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:59:18 by aet-tass          #+#    #+#             */
/*   Updated: 2023/03/07 23:50:08 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_abs(double x)
{
	if (x < 0.0)
		return (-x);
	else
		return (x);
}

int	check_burningship(t_mlx *mlx)
{
	double	modulus_squared;

	mlx->max_iter = 50;
	mlx->iter = 0;
	modulus_squared = mlx->z.re * mlx->z.re + mlx->z.im * mlx->z.im;
	while (modulus_squared < 4 && mlx->iter < mlx->max_iter)
	{
		mlx->tmp = mlx->z.re;
		mlx->z.re = mlx->z.re * mlx->z.re - mlx->z.im * mlx->z.im + mlx->c.re;
		mlx->z.im = 2 * ft_abs(mlx->z.im * mlx->tmp) + mlx->c.im;
		modulus_squared = mlx->z.re * mlx->z.re + mlx->z.im * mlx->z.im;
		mlx->iter++;
	}
	return (mlx->iter);
}

void	mapping_burningship(t_mlx *mlx)
{
	double	scale_factor;

	scale_factor = mlx->zoom / width;
	mlx->c.re = (mlx->win.i - width / 2.0) * scale_factor;
	mlx->c.im = (mlx->win.j - height / 2.0) * scale_factor;
}

void	burning_ship_set(t_mlx	*mlx)
{
	mlx->img_ptr = mlx_new_image(mlx->init_ptr, width, height);
	mlx->addr_ptr = mlx_get_data_addr(mlx->img_ptr, &mlx->bit_per_pixel,
			&mlx->line_lenght, &mlx->endian);
	mlx->z.re = 0;
	mlx->z.im = 0;
	mlx->max_iter = 50;
	mlx->win.i = 0;
	while (mlx->win.i < width)
	{
		mlx->win.j = 0;
		while (mlx->win.j < height)
		{
			mlx->z.re = 0;
			mlx->z.im = 0;
			mapping_burningship(mlx);
			mlx->iter = check_burningship(mlx);
			if (mlx->iter < 15)
				draw_fractal(mlx, mlx->win.i, mlx->win.j, 0x1DDFC4);
			else
				coloring(mlx);
			mlx->win.j++;
		}
		mlx->win.i++;
	}
	mlx_put_image_to_window(mlx->init_ptr, mlx->window_ptr, mlx->img_ptr, 0, 0);
}
