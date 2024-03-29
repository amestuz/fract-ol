/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:50:30 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/08/22 20:59:49 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>
# include "unistd.h"

# define SIZE_X 960
# define SIZE_Y 540

// KEYCODES
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define R 15
# define C 8
# define H 4
# define J 38
# define P 35
# define M 46

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractal;

// utils.c
void		my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color);
int			exit_fractal(t_fractal *fractal);
void		change_iterations(t_fractal *fractal, int key_code);
double		generate_random_c(void);

// mandelbrot.c
void		calculate_mandelbrot(t_fractal *fractal);

// julia.c
void		calculate_julia(t_fractal *fractal);

// mandelbrot_invers.c
void		calculate_mandelbrot_invers(t_fractal *fractal);

// mouse_and_keys.c
void		zoom(t_fractal *fractal, int x, int y, int zoom);
void		set_random_julia(t_fractal *fractal, double *cx, double *cy);
int			key_hook(int key_code, t_fractal *fractal);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

//init.c
void		init_fractal(t_fractal *fractal);
void		init_z(t_fractal *fractal);
void		init_c(t_fractal *fractal);
void		init_mlx(t_fractal *fractal);
// main.c
int			draw_fractal(t_fractal *fractal, char *query);
int			main(int argc, char **argv);

#endif