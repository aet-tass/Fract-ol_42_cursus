// Function to compute the Mandelbrot set for a given complex number
int compute_mandelbrot(double c_re, double c_im, int max_iter) {
    double re = 0.0, im = 0.0;
    double modulus_squared = 0.0;
    int iter = 0;
    while (modulus_squared < 4 && iter < max_iter) {
        double tmp = re;
        re = re * re - im * im + c_re;
        im = 2 * im * tmp + c_im;
        modulus_squared = re * re + im * im;
        iter++;
    }
    return iter;
}

// Function to compute the Mandelbrot set for each pixel in the image
void compute_mandelbrot_set(t_mlx *mlx, int max_iter) {
    double scale_factor = 4.0 / mlx->win.width;
    for (int y = 0; y < mlx->win.height; y++) {
        for (int x = 0; x < mlx->win.width; x++) {
            double c_re = (x - mlx->win.width / 2.0) * scale_factor;
            double c_im = (y - mlx->win.height / 2.0) * scale_factor;
            int iter = compute_mandelbrot(c_re, c_im, max_iter);
            mlx->image[y * mlx->win.width + x] = iter;
        }
    }
}

// Function to update the image on the screen
void update_image(t_mlx *mlx) {
    for (int y = 0; y < mlx->win.height; y++) {
        for (int x = 0; x < mlx->win.width; x++) {
            int color = mlx_get_color_value(mlx->mlx_ptr, getColor(mlx->image[y * mlx->win.width + x]));
            mlx_pixel_put(mlx->mlx_ptr, mlx->win.win_ptr, x, y, color);
        }
    }
}
