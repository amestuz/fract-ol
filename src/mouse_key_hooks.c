/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:46:06 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/08/25 20:40:28 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	else
		return ;
}

void	set_random_julia(t_fractal *fractal, double *cx, double *cy)
{
	*cx = generate_random_c();
	*cy = generate_random_c();
	fractal->cx = *cx;
	fractal->cy = *cy;
}

int	key_hook(int key_code, t_fractal *fractal)
{
	double	cx;
	double	cy;

	cx = fractal->cx;
	cy = fractal->cy;
	if (key_code == ESC)
		exit_fractal(fractal);
	else if (key_code == LEFT)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key_code == RIGHT)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == UP)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == DOWN)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == R)
		init_fractal(fractal);
	else if (key_code == C)
		fractal->color += (255 * 255 * 255) / 100;
	else if (key_code == J)
		set_random_julia(fractal, &cx, &cy);
	else if (key_code == M || key_code == P)
		change_iterations(fractal, key_code);
	mlx_clear_window(fractal->mlx, fractal->window);
	return (draw_fractal(fractal, fractal->name), 0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	int	zm;

	if (mouse_code == SCROLL_UP || mouse_code == SCROLL_DOWN)
	{
		if (mouse_code == SCROLL_UP)
			zm = 1;
		else
			zm = -1;
		zoom(fractal, (x - SIZE_X / 2), (y - SIZE_Y / 2), zm);
		mlx_clear_window(fractal->mlx, fractal->window);
		draw_fractal(fractal, fractal->name);
	}
	return (0);
}
