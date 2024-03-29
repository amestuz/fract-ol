/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:23:39 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/08/25 20:47:52 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->img_addr + (y * fractal->line_length \
		+ x * (fractal->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
/*	para comprobar leaks poner 
	system("leaks fractol");
	antes del exit
	
	Da leaks pero son de la mlx
	si se comenta la linea del //free(fractal->mlx)
	da leaks 0
	
	Pero valgrind da 0 leaks con algunos still reachable
	que son de la minilibx */

int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal->mlx);
	free(fractal);
	system("leaks fractol");
	exit(1);
	return (0);
}

void	change_iterations(t_fractal *fractal, int key_code)
{
	if (key_code == M)
	{
		if (fractal->max_iterations > 42)
			fractal->max_iterations -= 42;
	}
	else if (key_code == P)
	{
		if (fractal->max_iterations < 4200)
			fractal->max_iterations += 42;
	}
}

double	generate_random_c(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}
