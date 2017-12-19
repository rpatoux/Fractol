/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <rpatoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:58:06 by rpatoux           #+#    #+#             */
/*   Updated: 2017/04/29 15:51:35 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		calc_julia(t_var *my)
{
	double	x;
	double	y;

	x = my->new_re;
	y = my->new_im;
	my->new_re = x * x - y * y + my->re;
	my->new_im = 2 * x * y + my->im;
}

void		draw_julia(t_var *my)
{
	my->y = -1;
	if (!my->stay)
	{
		my->re = 0.285;
		my->im = 0.01;
	}
	while (++my->y < my->height)
	{
		my->x = -1;
		while (++my->x < my->width && (my->iter = -1))
		{
			my->new_re = (my->x - my->pos_x - ((my->width + my->w) / 2)) *
			(4.0 / my->width) / my->zoom;
			my->new_im = (my->y - my->pos_y - ((my->height + my->h) / 2)) *
			(4.0 / my->width) / my->zoom;
			while (((my->new_re * my->new_re + my->new_im * my->new_im) < 4)
			&& ++my->iter < my->maxi)
				calc_julia(my);
			write_data_pixel(my);
		}
	}
}
