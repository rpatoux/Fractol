/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <rpatoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:27:47 by rpatoux           #+#    #+#             */
/*   Updated: 2017/05/19 13:53:00 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>
# include <OpenCL/opencl.h>

typedef struct	s_var
{
	double				pos_x;
	double				pos_y;

	int					x_moove;
	int					y_moove;

	int					stay;

	int					h;
	int					w;

	int					maxi;
	int					iter;

	long double			zoom;

	float				re;
	float				im;
	double				new_re;
	double				new_im;
	int					colore;
	void				*mlx;
	void				*win;
	void				*img;

	unsigned long int	color;

	int					width;
	int					height;

	int					endian;
	int					bpp;
	int					sl;

	char				*data;

	int					x;
	int					y;

	char				*name;
}				t_var;

void			free_all(t_var *my);
int				main(int argc, char **argv);
void			write_data_pixel(t_var *my);
void			draw_mandelbrot(t_var *my);
int				mouse_motion(int x, int y, t_var *my);
int				mouse_funct(int button, int x, int y, t_var *my);
void			change_color_fractol(int keycode, t_var *my);
void			ft_new_screen(t_var *my);
int				key_funct(int keycode, t_var *my);
void			draw_julia(t_var *my);
void			draw_tricorn(t_var *my);
int				ft_init(t_var *my);
void			write_screen(t_var *my);
void			ft_init_pos(t_var *my);
void			ft_init_pos(t_var *my);

#endif
