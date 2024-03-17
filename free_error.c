/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:33:39 by ulyildiz          #+#    #+#             */
/*   Updated: 2024/03/17 06:03:51 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "mlx/mlx.h"
#include <stdlib.h>
#include <unistd.h>

static void	input_error(void)
{
	write(2, "For mandelbrot set type as: ", 28);
	write(2, "./fractol mandelbrot\n", 21);
	write(2, "For julia set type as: ", 23);
	write(2, "./fractol julia <first_parameter> <second_parameter>\n", 53);
	write(2, "Parameters have to be between -2 and 2\n", 39);
}

void	free_all(t_screen *window)
{
	if (window->set)
		free(window->set);
	if (window->win_ptr)
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	if (window->img_ptr)
		mlx_destroy_image(window->mlx_ptr, window->img_ptr);
}

void	error_occur(int flag, t_screen *window)
{
	if (flag == 1)
		input_error();
	else if (flag == 2)
	{
		free_all(window);
		write(2, "Program couldn't initiliaze window.\n", 36);
	}
	system("leaks fractol");
	exit(1);
}
