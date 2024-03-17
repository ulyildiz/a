/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:01:38 by ulyildiz          #+#    #+#             */
/*   Updated: 2024/03/17 03:01:38 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "define_bonus.h"

void	error_occur(int flag, t_screen *window);
void	free_all(t_screen *window);

void	check_point(int ac, const char *av[]);

int		ft_strcmp(const char *s1, const char *s2);
double	atoi_point(const char *str);

void	draw_fract(t_screen *window);
int		calc_for_mandel(t_complex c, t_screen *window);
int		calc_for_julia(t_complex pixels, t_screen *window);
int		calc_for_bship(t_complex c, t_screen *window);
void	hook_event(t_screen *window);

#endif