/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_invers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:10:29 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/08/20 19:39:37 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	calculate_mandelbrot_invers(t_fractal *fractal)
{
	int		it;
	double	x_calc;

	fractal->name = "brotinv";
	it = 0;
	init_z(fractal);
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (++it < fractal->max_iterations)
	{
		x_calc = fractal->zx * fractal->zx - fractal->zy * fractal->zy + \
		fractal->cx / (fractal->cx * fractal->cx + fractal->cy * fractal->cy);
		fractal->zy = 2 * fractal->zx * fractal->zy - fractal->cy / (\
			fractal->cx * fractal->cx + fractal->cy * fractal->cy);
		fractal->zx = x_calc;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (it == fractal->max_iterations)
		my_mlx_pixel_put(fractal, fractal->x + SIZE_X / 2,
			fractal->y + SIZE_Y / 2, 0xFFFFFF);
	else
		my_mlx_pixel_put(fractal, fractal->x + SIZE_X / 2,
			fractal->y + SIZE_Y / 2, (fractal->color * it));
}
