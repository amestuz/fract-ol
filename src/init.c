/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:57:56 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/08/22 20:58:22 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->color = 0xFCBE11;
	fractal->zoom = 200;
	fractal->offset_x = 0;
	fractal->offset_y = 0;
	fractal->max_iterations = 100;
}

void	init_z(t_fractal *fractal)
{
	fractal->zx = 0;
	fractal->zy = 0;
}

void	init_c(t_fractal *fractal)
{
	fractal->cx = -0.745429;
	fractal->cy = 0.05;
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, SIZE_X, SIZE_Y, "Fract-ol");
	fractal->image = mlx_new_image(fractal->mlx, SIZE_X, SIZE_Y);
	fractal->img_addr = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel,
			&fractal->line_length,
			&fractal->endian);
}
