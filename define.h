/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:33:53 by ulyildiz          #+#    #+#             */
/*   Updated: 2024/03/17 05:49:41 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define WIDTH 900
# define HEIGHT 900
# define MX_R 4
# define MAX_ITER 600
# define THRESHOLD 20

# define ESC 53
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
}						t_set;

typedef struct s_screen
{
	t_set				*set;
	const char			*fract_name;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*img_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_screen;

#endif