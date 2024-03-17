/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:33:42 by ulyildiz          #+#    #+#             */
/*   Updated: 2024/03/17 05:38:31 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "define.h"

void	error_occur(int flag, t_screen *window);
void	free_all(t_screen *window);

void	check_point(int ac, const char *av[]);

int		ft_strcmp(const char *s1, const char *s2);
double	atoi_point(const char *str);

int		init_fract(t_screen *window, const char *av[]);
void	draw_fract(t_screen *window);
int		calc_for_mandel(t_complex c, t_screen *window);
int		calc_for_julia(t_complex pixels, t_screen *window);
void	hook_event(t_screen *window);

#endif