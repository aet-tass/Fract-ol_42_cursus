/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:40:54 by aet-tass          #+#    #+#             */
/*   Updated: 2023/03/08 00:46:43 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	arg_stored(int ac, char **av, t_mlx *mlx)
{
	if (ac == 2 && ft_atoi(av[1]) == 1)
	{
		mlx->arg = 1;
		return (1);
	}
	else if (ac == 4 && ft_atoi(av[1]) == 2)
	{
		if ((float_atoi(av[2]) <= 2 && float_atoi(av[2]) >= -2)
				&& (float_atoi(av[23]) <= 2 && float_atoi(av[3]) >= -2))
		{
			mlx->arg = 2;
			mlx->c.re = float_atoi(av[2]);
			mlx->c.im = float_atoi(av[3]);
			return (1);
		}
	}
	else if(ac == 2 && ft_atoi(av[1]) == 3)
	{
		mlx->arg = 3;
		return (1);
	}
	return (0);
}

void ft_error()
{
    ft_putstr_fd("\n", 2);
    ft_putstr_fd("Hey There !\n", 2);
    ft_putstr_fd("-------------------------------- // ----------------------------------------------\n", 2);
    ft_putstr_fd("Would you like to dazzle your eyes by watching some fractals ... ?\n", 2);
    ft_putstr_fd(" --> Then here is what you have to do :\n", 2);
    ft_putstr_fd("\n", 2);
    ft_putstr_fd(" -> if you want to see Mandelbrot_set , your argument must be as bellow :\n", 2);
    ft_putstr_fd("      ./fractol 1\n", 2);
    ft_putstr_fd("-> if you want to see Julia_set , your argument must be as bellow :\n", 2);
    ft_putstr_fd("      ./fractol 2 c_re c_img\n", 2);
    ft_putstr_fd("       Note That : -2 < c_re < 2 && -2 < c_img < 2\n", 2);
    ft_putstr_fd("       here is some famous julia_set's coordinates : -0.8 0.156 /  -0.4 0.6\n", 2);
    
    ft_putstr_fd("-> if you want to see Burning_ship_set , your argument must be as bellow :\n", 2);
    ft_putstr_fd("      ./fractol 3\n", 2);
    ft_putstr_fd("Enjoy !\n", 2);
    ft_putstr_fd("-------------------------------- // ---------------------------------------------\n", 2);
    ft_putstr_fd("\n", 2);
    ft_putstr_fd("\n", 2);
}

int	main(int    ac, char    **av)
{
    t_mlx   mlx;
    ft_init(&mlx);

    if (arg_stored(ac, av, &mlx))
    {
        
        if (mlx.arg == 1)
            mandelbrot_set(&mlx);
        else if (mlx.arg == 2)
            julia_set(&mlx);
        else if(mlx.arg == 3)
            burning_ship_set(&mlx);
        mlx_mouse_hook(mlx.window_ptr, zoom, &mlx);
        mlx_key_hook(mlx.window_ptr, &handle_keypress, &mlx);
        mlx_loop(mlx.init_ptr);
    }
    else 
        ft_error();
	
}
