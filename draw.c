/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:33:47 by ulyildiz          #+#    #+#             */
/*   Updated: 2024/03/17 05:48:02 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx/mlx.h"
#include <math.h>

static int	get_color(int iteration)
{
	t_byte	red;
	t_byte	green;
	t_byte	blue;

	if (iteration == MAX_ITER)
		return (0);
	red = (sin(iteration * 0.001) + 1) / 2 * 255;
	green = (sin(iteration * 0.01) + 1) / 2 * 255;
	blue = (sin(iteration * 0.1) + 1) / 2 * 255;
	return (red << 16 | green << 8 | blue);
}

static void	put_pixels(t_screen *window, int x, int y, int color)
{
	int	offset;

	offset = (window->size_line * y) + (x * window->bits_per_pixel / 8);
	*((unsigned int *)(offset + window->img_addr)) = color;
}

static int	choose_formula(t_complex pixels, t_screen *window)
{
	if (window->fract_name[0] == 'j')
		return (calc_for_julia(pixels, window));
	else if (window->fract_name[0] == 'm')
		return (calc_for_mandel(pixels, window));
	return (-1);
}

void	draw_fract(t_screen *window)
{
	int			x;
	int			y;
	t_complex	pixels;
	int			color;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			pixels.re = window->set->min_re + (window->set->max_re
					- window->set->min_re) * x / WIDTH;
			pixels.im = window->set->min_im + (window->set->max_im
					- window->set->min_im) * y / HEIGHT;
			color = get_color(choose_formula(pixels, window));
			window->set->iteration = -1;
			put_pixels(window, x, y, color);
		}
	}
}
