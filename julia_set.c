/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:55:07 by aet-tass          #+#    #+#             */
/*   Updated: 2023/02/21 17:01:04 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

int		check_condition(t_mlx *mlx)
{
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
	double	scale_factor;
	scale_factor = mlx->zoom / width;
	mlx->z.re = (mlx->win.i - width / 2.0) * scale_factor;
	mlx->z.im	=(mlx->win.j - height / 2.0) * scale_factor; 
}

void	julia_set(t_mlx	*mlx)
{
	mlx->c.re = -0.8;
	mlx->c.im = 0.156;
	mlx->max_iter = 50;
	mlx->win.i = 0;
	while (mlx->win.i < width)
	{
		mlx->win.j = 0;
		while (mlx->win.j < height)
		{
			mlx->z.re = 0;
			mlx->z.im = 0;
			mapping_pixels(mlx);
			mlx->iter = check_condition(mlx); 
			int	color1 = mlx->iter % 16 * 0x0F1011+ mlx->iter % 16 * 0xE9E9E9 +  mlx->iter % 16 * 0x2D3030 ;
			int	color2 = mlx->iter % 16 * 0x0F1011 + mlx->iter % 16 * 0xF2D027 ;
			 if (mlx->iter < 17)
		 		draw_fractal(mlx,  mlx->win.i ,  mlx->win.j , color1);
			 else if (mlx->iter < 50)
			 	draw_fractal(mlx,  mlx->win.i ,mlx->win.j , color2);
	 		 else
		 	 	draw_fractal(mlx,  mlx->win.i ,  mlx->win.j , 0xFFFFFF);
			mlx->win.j++;
		}
		mlx->win.i++;
		
	}
	mlx_put_image_to_window(mlx->init_ptr, mlx->window_ptr, mlx->img_ptr, 0, 0);
}
		

// int	main()
// {
// 	t_mlx	mlx;
// 	ft_init(&mlx);
// 	julia_set(&mlx);

// 	mlx_loop(mlx.init_ptr);
// }