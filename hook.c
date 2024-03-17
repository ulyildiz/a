/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:33:29 by ulyildiz          #+#    #+#             */
/*   Updated: 2024/03/17 02:31:54 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx/mlx.h"

static int	key_event(int keycode, t_screen *window)
{
	if (keycode == ESC)
		free_all(window);
	return (0);
}

static int	closing(t_screen *window)
{
	free_all(window);
	return (0);
}

static int	mouse_event(int keycode, int x, int y, t_screen *window)
{
	x = y;
	if (keycode == SCROLL_UP)
		window->set->zoom_factor *= 0.9;
	else if (keycode == SCROLL_DOWN)
		window->set->zoom_factor *= 1.1;
	draw_fract(window);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->img_ptr,
		0, 0);
	return (0);
}

void	hook_event(t_screen *window)
{
	mlx_hook(window->win_ptr, 2, 0, key_event, window);
	mlx_hook(window->win_ptr, 17, 1, closing, window);
	mlx_hook(window->win_ptr, 4, (1L << 4), mouse_event, window);
}
