// mlx->zoom = 4.0;

// if (key == 4)
//     mlx->zoom /= 1.2;
// else if (key == 5)
//     mlx->zoom *= 1.2;
// if (julia)
//     ft_julia();
// else if (man)
//     ft_man();

int	main()
{
	t_mlx	mlx;
	ft_init(&mlx);
	julia_set(&mlx);

	mlx_loop(mlx.init_ptr);
}