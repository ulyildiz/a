/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:29:42 by ulyildiz          #+#    #+#             */
/*   Updated: 2024/03/17 02:29:42 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define_bonus.h"
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
	write(2, "For burningship type as: ", 25);
	write(2, "./fractol burningship\n", 22);
	exit(1);
}

void	free_all(t_screen *window)
{
	if (window->set)
		free(window->set);
	if (window->win_ptr)
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	if (window->img_ptr)
		mlx_destroy_image(window->mlx_ptr, window->img_ptr);
	exit(1);
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
}
