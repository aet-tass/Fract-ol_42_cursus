/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:28:52 by aet-tass          #+#    #+#             */
/*   Updated: 2023/03/09 13:43:32 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(t_mlx *mlx)
{
	mlx->init_ptr = mlx_init();
	mlx->window_ptr = mlx_new_window(mlx->init_ptr, WIDTH, HEIGHT, TITLE);
	mlx->zoom = 4.0;
}

int	draw_fractal(t_mlx *mlx, int w, int h, int color)
{
	char	*addr;

	addr = mlx->addr_ptr + (h * mlx->line_lenght + w * (mlx->bit_per_pixel
				/ 8));
	*(unsigned int *)addr = color;
	return (0);
}

int	get_color(t_mlx *mlx)
{
	int	color;

	if (mlx->max_iter < 2)
		color = 0xffffff;
	else if (mlx->max_iter < 4)
		color = 0xf5f3f4;
	else if (mlx->max_iter < 8)
		color = 0xd3d3d3;
	else
		color = 0xede0d4;
	return (color);
}

void	coloring(t_mlx *mlx)
{
	mlx->color = get_color(mlx);
	if (mlx->iter < mlx->max_iter)
		draw_fractal(mlx, mlx->win.i, mlx->win.j, mlx->color);
	else
		draw_fractal(mlx, mlx->win.i, mlx->win.j, 0x000000);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}
