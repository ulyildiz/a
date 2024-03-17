/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:51:50 by ulyildiz          #+#    #+#             */
/*   Updated: 2024/03/17 03:51:50 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_BONUS_H
# define DEFINE_BONUS_H

# define WIDTH 600
# define HEIGHT 600
# define MX_R 4
# define MAX_ITER 500
# define THRESHOLD 20

# define ESC 53
# define UP 126
# define DOWN 125
# define RIGHT 123
# define LEFT 124
# define R_OPTION 262
# define ENTER 36
# define SCROLL_UP 5
# define SCROLL_DOWN 4

typedef unsigned char	t_byte;

typedef struct s_complex
{
	double				re;
	double				im;
}						t_complex;

typedef struct s_set
{
	double				max_re;
	double				max_im;
	double				min_re;
	double				min_im;
	double				zoom_factor;
	t_complex			c;
	int					iteration;
	int					color_code;
}						t_set;

typedef struct s_screen
{
	t_set				*set;
	const char			*fract_name;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	const char			*img_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	int					motion;
}						t_screen;

#endif