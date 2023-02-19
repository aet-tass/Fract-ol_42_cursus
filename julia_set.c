/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:55:07 by aet-tass          #+#    #+#             */
/*   Updated: 2023/02/19 20:03:30 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	julia_set(t_mlx *mlx)
{
	int	max_iter;
	int	iter;
	double	sqrt_modulus;
	double	scale_factor;
	int		height;
	int		width;
	t_mlx	nb;
	t_mlx	win;
	
	max_iter = 50;
	iter = 0;
	while (win.i < width)
	{
		win.j = 0;
		{	
			
			nb.c.re = 0.285;
			nb.c.im = 0.01;
			scale_factor = 4.0 / width;
			nb.z.re = (win.i - width / 2.0) * scale_factor;
			nb.z.im	=(win.j - height / 2.0) * scale_factor;

			sqrt_modulus = nb.z.re * nb.z.re + nb.z.im * nb.z.im;
			while ( sqrt_modulus < 4 && iter < max_iter)
			{
				double	tmp;
				tmp = nb.z.re;
				nb.z.re = nb.z.re * nb.z.re - nb.z.im * nb.z.im + nb.c.re;
				nb.z.im = 2 * nb.z.im * tmp + nb.c.im;
				sqrt_modulus = nb.z.re * nb.z.re + nb.z.im * nb.z.im;
				iter++;
			}
		}
	}
}

