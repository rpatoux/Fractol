/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <rpatoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:18:59 by rpatoux           #+#    #+#             */
/*   Updated: 2017/05/19 12:10:07 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		check_name(char *argv)
{
	if (!ft_strcmp(argv, "Julia") || !ft_strcmp(argv, "Mandelbrot") ||
	!ft_strcmp(argv, "Tricorn"))
		return (1);
	return (0);
}

void			write_data_pixel(t_var *my)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (my->iter == 0)
		my->color = my->colore / 1;
	else
		my->color = my->colore / my->iter * 10;
	b = (my->color & 0xFF0000) >> 16;
	g = (my->color & 0xFF00) >> 8;
	r = (my->color & 0xFF);
	if (my->x >= 0 && my->y >= 0 && my->x < my->width && my->y < my->height)
	{
		my->data[my->y * my->sl + my->x * (my->bpp / 8)] = r;
		my->data[my->y * my->sl + my->x * (my->bpp / 8) + 1] = g;
		my->data[my->y * my->sl + my->x * (my->bpp / 8) + 2] = b;
	}
}

int				fractol(t_var *my)
{
	if (!strcmp(my->name, "Mandelbrot"))
		draw_mandelbrot(my);
	if (!strcmp(my->name, "Julia"))
		draw_julia(my);
	if (!strcmp(my->name, "Tricorn"))
		draw_tricorn(my);
	mlx_put_image_to_window(my->mlx, my->win, my->img, 0, 0);
	write_screen(my);
	return (1);
}

void			begin_mlx(t_var *my)
{
	my->width = 1300;
	my->height = 1300;
	my->sl = my->width * (my->bpp / 8);
	my->mlx = mlx_init();
	my->win = mlx_new_window(my->mlx, my->width, my->height, "Fract'ol");
	my->img = mlx_new_image(my->mlx, my->width, my->height);
	my->data = mlx_get_data_addr(my->img, &my->bpp, &my->sl, &my->endian);
}

int				main(int argc, char **argv)
{
	t_var	*my;

	if ((my = NULL) == NULL && argc != 2)
	{
		ft_putstr("Usage : ./fractol <fractal name>\n");
		exit(EXIT_FAILURE);
	}
	if (!(my = (t_var *)malloc(sizeof(t_var))))
		exit(EXIT_FAILURE);
	if (check_name(argv[1]) && (my->name = ft_strdup(argv[1])) && ft_init(my))
	{
		begin_mlx(my);
		fractol(my);
		mlx_loop_hook(my->mlx, fractol, my);
		mlx_hook(my->win, KeyPress, KeyPressMask, key_funct, my);
		mlx_hook(my->win, ButtonPress, ButtonPressMask, mouse_funct, my);
		mlx_hook(my->win, MotionNotify, ButtonMotionMask, mouse_motion, my);
		mlx_loop(my->mlx);
	}
	else
		ft_putstr("Fractal :\nJulia\nMandelbrot\nTricorn\n");
	return (0);
}
