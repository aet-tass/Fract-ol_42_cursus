#include <stdio.h>
#include <mlx.h>
#include <math.h>
# define width 1000
# define height 1000

typedef	struct	s_z
{
	double	re;
	double	im;
} t_z;

typedef struct s_mlx
{
	void *init;
	void *window;
	void *img;
	char *addr;
	int bit_per_pixel;
	int line_lenght;
	int endian;
	int max_iter;
	int iter;
	t_z z;
	t_z c;
	double tmp;

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

int draw_fractal(t_mlx *mlx, int w, int h, int color)
{
	char *addr;

	addr = mlx->addr + (h * mlx->line_lenght + w * (mlx->bit_per_pixel / 8));
	*(unsigned int *)addr = color;
	return (0);
}

int		check_condition(t_mlx *mlx)
{
	mlx->z.re = 0;
	mlx->z.im = 0;
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
	mlx->max_iter = 50;
	double	scale_factor;
	scale_factor = 4.0 / width;
	int i = 0, j = 0;
	while (i < width)
	{
		while (j < height)
		{
			mlx->c.re = (i - width / 2.0) * scale_factor;
			mlx->c.im	=(j - height / 2.0) * scale_factor;
			mlx->iter = check_condition(mlx); 
			
		j++;
		}
		i++;
	}	
		
	
}

void    mandelbrot_set(t_mlx *mlx)
{
	int	max_iteration = 50;
	double	z_re = 0;
	double	z_img = 0;
	double	c_re = 0;
	double	c_img = 0;
	int	i = 0;
	int y = 0, x = 0;
	double sqrt_modulus ;
	double	scale_factor;
	int	color;

	while (x < width)
	{
		y = 0;
		while (y < height)
		{

			// z_re = 0;
			// z_img = 0;
			// scale_factor = 4.0/ width;
			// c_re = (x - width / 2.0) * scale_factor;
			// c_img = (y - height / 2.0) * scale_factor;
			// i = 0;
			// //modulo = sqrt(pow(z_re, 2) + pow(z_img, 2));
			// sqrt_modulus = z_re * z_re + z_img * z_img;
     		// while ( sqrt_modulus < 4 &&  i < max_iteration)
			// {
         	// 	double	tmp ;
			// 	tmp = z_re;
			// 	/*
		 	// 	* We store zr in a temporary variable to avoid using the
		 	// 	* new value of zr in the z_img calculation
			// 	*/
        	//  	z_re = z_re * z_re - z_img * z_img + c_re;
         	// 	z_img = 2 * z_img * tmp + c_img;
			// 	//modulo  = sqrt(pow(z_re, 2) + pow(z_img, 2));	
			// 	sqrt_modulus = z_re * z_re + z_img * z_img;
         	// 	i++;
			// }
			mapping_pixels(mlx);
			//mlx->iter = check_condition(mlx);
			int	color = i % 16 * 0x000000+ i % 16 * 0xFFFFFF;
			int	color2 = i % 16 * 0xF90000 + i % 16 * 0xF2D027;
			if (i < 17)
		 		draw_fractal(mlx, x ,  y, color);
			else if (i < 50)
				draw_fractal(mlx,  x , y, color2);
	 		else
		 		draw_fractal(mlx, x , y, 0x000000);

			y++;
		}
	 	x++;
	}
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->img, 0, 0);
	mlx_loop(mlx->init);
}

int main()
{
	t_mlx mlx;
	

	mlx.init = mlx_init();

	mlx.window = mlx_new_window(mlx.init, 1000, 1000, "et-tass");
	
	mlx.img = mlx_new_image(mlx.init, 1000, 1000);

	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bit_per_pixel, &mlx.line_lenght, &mlx.endian);

	//draw_fractal(&mlx, width, height, mlx.color);

	//mlx_put_image_to_window(mlx.init, mlx.window, mlx.img, 0, 0);
	
	// mlx_pixel_put(init, window, 250, 250, 0x10FF0000);

	// mlx_string_put(init, window, 100, 100, 0xFFFFFFFF, "tass");

	// mlx_key_hook(window, fucntion_handle, &mlx);

	// mlx_mouse_hook(mlx.window, handle, &mlx);
	
	mandelbrot_set(&mlx);

	mlx_loop(mlx.init);
}

/*
 * First of all, you should know that the Mandelbrot set is always
 * between -2.1 and 0.6 on the x-axis and between -1.2 and 1.2 on the
 * Ordered
 */
