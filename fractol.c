#include "fractol.h"


int arg_stored(int ac, char **av, t_mlx *mlx)
{
    if (ac == 2 && ft_atoi(av[1]) == 1)
    {
        mlx->arg = 1;
        return (1);
    } else if (ac == 4 && ft_atoi(av[1]) == 2)
    {
        if ((float_atoi(av[2]) <= 2 && float_atoi(av[2] >= -2)) && (float_atoi(av[23]) <= 2 && float_atoi(av[3] >= -2)))
        {
            mlx->arg = 2;
            return (1);        
        }
    }
    return (0);
}




int	main(int    ac, char    **av)
{
    t_mlx   *mlx;
    ft_init(&mlx);

    if (arg_stored(ac, av, &mlx))
{
    if (mlx->arg == 1)
        ft_mndelbrot(&mlx);
    else 
        ft_julia(&mlx);
    
    mlx_loop(mlx->init_ptr);
}
else 
    ft_errorL();
	mlx_loop(mlx->init_ptr);
}