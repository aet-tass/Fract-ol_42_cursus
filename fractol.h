/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:42:42 by aet-tass          #+#    #+#             */
/*   Updated: 2023/02/19 23:15:56 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <mlx.h>
# define	width 1000
# define	height 1000
# define	title	"Ayoub's Fractal"

// typedef	struct	s_mlx
// {
// 	void	*init_ptr;
// 	void	*window_ptr;
// 	char	*img_ptr;
// 	char	*addr_ptr;
// 	int		bit_per_pixel;
// 	int		line_lenght;
// 	int		endian;
// 	int		iter;
// 	int		max_iter;
// 	int		iter;
// 	double	tmp;
// 	t_coord	win;
// 	t_c 	c;
// 	t_z		z;
// }	t_mlx;

typedef	struct	s_z
{
	double	re;
	double	im;
} t_z;

typedef	struct	s_c
{
	double	re;
	double	im;
}	t_c;

typedef	struct s_coord
{
	int	i;
	int	j;
}	t_coord;

typedef	struct	s_mlx
{
	void	*init_ptr;
	void	*window_ptr;
	char	*img_ptr;
	char	*addr_ptr;
	int		bit_per_pixel;
	int		line_lenght;
	int		endian;
	int		iter;
	int		max_iter;
	double	tmp;
	t_coord	win;
	t_c 	c;
	t_z		z;
}	t_mlx;


int draw_fractal(t_mlx *mlx, int w , int h , int color );
void	mandelbrot_set(t_mlx *mlx);
void	julia_set(t_mlx *mlx);
void    ft_init(t_mlx *mlx);

#endif