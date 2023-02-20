/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:33:25 by aet-tass          #+#    #+#             */
/*   Updated: 2023/02/20 15:45:56 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int draw_fractal(t_mlx *mlx, int width, int height, int color)
{
	char *addr;

	addr = mlx->addr_ptr + (height * mlx->line_lenght + width * (mlx->bit_per_pixel / 8));
	*(unsigned int *)addr = color;
	return (0);
}

// int color_add(t_mlx mlx)
// {
//     int 
//     int color1  i % 16 + 
// }