/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:14:06 by aet-tass          #+#    #+#             */
/*   Updated: 2023/02/21 20:01:23 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


// int mlx_check(int ac, char **av, t_mlx *mlx)
// {
//     if (ac == 2 && atoi(av[1]) == 1)
//     {
//         mlx->arg = 1;
//         return (1);
//     } else if (ac == 4 && atoi(av[1]) == 2)
//     {
//         if ((double(av[2]) <= 2 && double(av[2] >= -2)) && (double(av[23]) <= 2 && double(av[3] >= -2)))
//         {
//             mlx->arg = 2;
//             return (1);        
//         }
//     }
//     return (0);
// }

//                 // main 

// mlx_init();

// if (mlx_check(ac, av, &mlx))
// {
//     if (mlx.arg == 1)
//         ft_mndelbrot(&mlx);
//     else 
//         ft_julia(&mlx);
    
//     mlx_loop(ptr);
// }
// else 
//     ft_errorL();