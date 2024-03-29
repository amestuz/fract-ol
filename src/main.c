/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:45:48 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/08/22 20:58:46 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	draw_fractal(t_fractal *fractal, char *name)
{
	fractal->x = - (SIZE_X / 2);
	while (++fractal->x < SIZE_X / 2)
	{
		fractal->y = SIZE_Y / 2;
		while (--fractal->y > - (SIZE_Y / 2))
		{
			if (ft_strncmp(name, "mandel", 7) == 0)
				calculate_mandelbrot(fractal);
			else if (ft_strncmp(name, "julia", 6) == 0)
				calculate_julia(fractal);
			else if (ft_strncmp(name, "brotinv", 8) == 0)
				calculate_mandelbrot_invers(fractal);
			else
			{
				ft_putendl_fd("USAGE: ./fractol <fractal>", 1);
				ft_putendl_fd("Available <fractal>: mandel, julia, brotinv", 1);
				ft_putendl_fd("KEY C:col M/P:it R:re_0 J:C_rndm ARROWS:mov", 1);
				ft_putendl_fd("MOUSE SCROLL:zoom", 1);
				exit_fractal(fractal);
			}
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc != 2)
	{
		ft_putendl_fd("USAGE: ./fractol <fractal>", 1);
		ft_putendl_fd("Available <fractal>: mandel, julia, brotinv", 1);
		ft_putendl_fd("KEY C:color M/P:iter R:reboot J:C_randm ARROWS:move", 1);
		ft_putendl_fd("MOUSE SCROLL:zoom", 1);
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	init_c(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
