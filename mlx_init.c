/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:28:52 by aet-tass          #+#    #+#             */
/*   Updated: 2023/03/07 21:39:52 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_init(t_mlx *mlx)
{
    mlx->init_ptr = mlx_init();
    mlx->window_ptr = mlx_new_window(mlx->init_ptr, width, height, title);
    mlx->zoom = 4.0;
}

int draw_fractal(t_mlx *mlx, int w, int h, int color)
{
	char *addr;

	addr = mlx->addr_ptr + (h * mlx->line_lenght + w * (mlx->bit_per_pixel / 8));
	*(unsigned int *)addr = color;
	return (0);
}
