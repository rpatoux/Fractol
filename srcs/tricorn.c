/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <rpatoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 15:07:55 by rpatoux           #+#    #+#             */
/*   Updated: 2017/04/29 15:52:44 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		calc_tricorn(t_var *my)
{
	my->re = ((my->y - my->pos_y -
	((my->width + my->h) / 2.0)) * (4.0 / my->width) / my->zoom);
	my->im = ((my->x - my->pos_x -
	((my->height + my->w) / 2.0)) * (4.0 / my->width) / my->zoom);
}

void			draw_tricorn(t_var *my)
{
	double		x;
	double		y;
	double		x_new;

	my->x = -1;
	while (++my->x < my->height)
	{
		my->y = -1;
		while (++my->y < my->width && (my->iter = -1))
		{
			calc_tricorn(my);
			y = 0;
			x = 0;
			while (x * x + y * y <= 4 && ++my->iter < my->maxi)
			{
				x_new = x * x - y * y + my->re;
				y = -2 * x * y + my->im;
				x = x_new;
			}
			write_data_pixel(my);
		}
	}
}
