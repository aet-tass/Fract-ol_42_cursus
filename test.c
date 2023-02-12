/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:53:23 by aet-tass          #+#    #+#             */
/*   Updated: 2023/02/12 21:26:41 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct s_mlx
{
	void *init;
	void *window;
	void *img;
	char *addr;
	int bit_per_pixel;
	int line_lenght;
	int endian;
}	t_mlx;

/*int fucntion_handle(int key, void *param){
	printf("%d\n", key);
	return (0);
}

int handle(int button, int x, int y, t_mlx *mlx)
{

	mlx_pixel_put(mlx->init, mlx->window, x, y, mlx->color);

	return (0);
}*/

int draw_shape(t_mlx *mlx, int x, int y, int color)
{
	char *addr;

	addr = mlx->addr + (y * mlx->line_lenght + x * (mlx->bit_per_pixel / 8));
	*(unsigned int *)addr = color;
	return (0);
}

int main()
{
	t_mlx mlx;
	

	mlx.init = mlx_init();

	mlx.window = mlx_new_window(mlx.init, 500, 500, "et-tass");
	
	mlx.img = mlx_new_image(mlx.init, 500, 500);

	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bit_per_pixel, &mlx.line_lenght, &mlx.endian);

	draw_shape(&mlx, 100, 100, 0xFFFFFF);

	mlx_put_image_to_window(mlx.init, mlx.window, mlx.img, 0, 0);
	
	// mlx_pixel_put(init, window, 250, 250, 0x10FF0000);

	// mlx_string_put(init, window, 100, 100, 0xFFFFFFFF, "tass");

	// mlx_key_hook(window, fucntion_handle, &mlx);

	// mlx_mouse_hook(mlx.window, handle, &mlx);

	mlx_loop(mlx.init);
}
