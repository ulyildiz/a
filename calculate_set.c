/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:34:06 by ulyildiz          #+#    #+#             */
/*   Updated: 2024/03/17 02:59:45 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

static t_complex	sum_co(t_complex num1, t_complex num2)
{
	t_complex	res;

	res.im = num1.im + num2.im;
	res.re = num1.re + num2.re;
	return (res);
}

static t_complex	square_co(t_complex num1)
{
	t_complex	res;

	res.re = num1.re * num1.re - num1.im * num1.im;
	res.im = 2 * num1.im * num1.re;
	return (res);
}

int	init_fract(t_screen *window, const char *av[])
{
	t_set	*fract;

	fract = (t_set *)malloc(sizeof(t_set));
	if (!fract)
		return (0);
	if (!ft_strcmp("julia", window->fract_name))
	{
		fract->c.re = atoi_point(av[2]);
		fract->c.im = atoi_point(av[3]);
	}
	window->set = NULL;
	window->mlx_ptr = NULL;
	window->win_ptr = NULL;
	window->img_ptr = NULL;
	window->img_addr = NULL;
	fract->min_re = -2;
	fract->max_re = 2;
	fract->min_im = -2;
	fract->max_im = fract->min_im + (fract->max_re - fract->min_re) * HEIGHT
		/ WIDTH;
	fract->iteration = -1;
	window->set = fract;
	return (1);
}

int	calc_for_mandel(t_complex c, t_screen *window)
{
	t_complex	z;

	z.re = 0;
	z.im = 0;
	while (++window->set->iteration < MAX_ITER)
	{
		if (z.re * z.re + z.im * z.im > MX_R)
			break ;
		z = sum_co(square_co(z), c);
	}
	return (window->set->iteration);
}

int	calc_for_julia(t_complex z, t_screen *window)
{
	while (++window->set->iteration < MAX_ITER)
	{
		if (z.re * z.re + z.im * z.im > THRESHOLD)
			break ;
		z = sum_co(square_co(z), window->set->c);
	}
	return (window->set->iteration);
}
