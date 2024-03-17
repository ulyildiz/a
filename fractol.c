/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:33:45 by ulyildiz          #+#    #+#             */
/*   Updated: 2024/03/17 05:49:08 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx/mlx.h"
#include <stdlib.h>

static void	setup_window(t_screen *window)
{
	window->mlx_ptr = mlx_init();
	if (!window->mlx_ptr)
		error_occur(2, window);
	window->win_ptr = mlx_new_window(window->mlx_ptr, WIDTH, HEIGHT,
			(char *)window->fract_name);
	if (!window->win_ptr)
		error_occur(2, window);
	window->img_ptr = mlx_new_image(window->mlx_ptr, WIDTH, HEIGHT);
	if (!window->img_ptr)
		error_occur(2, window);
	window->img_addr = mlx_get_data_addr(window->img_ptr,
			&(window->bits_per_pixel), &(window->size_line), &(window->endian));
	if (!window->img_addr)
		error_occur(2, window);
}

int	main(int argc, const char **argv)
{
	t_screen	window;

	if (argc < 2)
		return (1);
	check_point(argc, argv + 1);
	window.fract_name = argv[1];
	if (!init_fract(&window, argv))
		return (1);
	setup_window(&window);
	draw_fract(&window);
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.img_ptr, 0,
		0);
	hook_event(&window);
	mlx_loop(window.mlx_ptr);
	return (0);
}
