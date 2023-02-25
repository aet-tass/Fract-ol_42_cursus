/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:40:54 by aet-tass          #+#    #+#             */
/*   Updated: 2023/02/24 22:40:57 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int arg_stored(int ac, char **av, t_mlx *mlx)
{
    if (ac == 2 && ft_atoi(av[1]) == 1)
    {
        mlx->arg = 1;
        return (1);
    } else if (ac == 4 && ft_atoi(av[1]) == 2)
    {
        if ((float_atoi(av[2]) <= 2 && float_atoi(av[2]) >= -2) && (float_atoi(av[23]) <= 2 && float_atoi(av[3]) >= -2))
        {
            mlx->arg = 2;
            mlx->c.re = float_atoi(av[2]);
	        mlx->c.im = float_atoi(av[3]);
            return (1);        
        }
    }
    return (0);
}

void ft_error()
{
    printf("Erorr");
}


int	main(int    ac, char    **av)
{
    t_mlx   mlx;
    ft_init(&mlx);

    if (arg_stored(ac, av, &mlx))
    {
        
        if (mlx.arg == 1)
            mandelbrot_set(&mlx);
        else 
            julia_set(&mlx);
        mlx_mouse_hook(mlx.window_ptr, zoom, &mlx);
        mlx_loop(mlx.init_ptr);
    }
    else 
        ft_error();
	
}
