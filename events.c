/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:14:06 by aet-tass          #+#    #+#             */
/*   Updated: 2023/03/08 01:54:59 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_image(mlx->init_ptr, mlx->img_ptr);
		mlx_clear_window(mlx->init_ptr, mlx->window_ptr);
		exit(0);
	}
	return (0);
}

int	zoom(int key, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (key == 4 || key == 5)
	{
		mlx_destroy_image(mlx->init_ptr, mlx->img_ptr);
		mlx_clear_window(mlx->init_ptr, mlx->window_ptr);
		if (key == 5)
			mlx->zoom /= 1.1;
		else if (key == 4)
			mlx->zoom *= 1.1;
		if (mlx->arg == 1)
			mandelbrot_set(mlx);
		else if (mlx->arg == 2)
			julia_set(mlx);
		else if (mlx->arg == 3)
			burning_ship_set(mlx);
	}
	return (0);
}
