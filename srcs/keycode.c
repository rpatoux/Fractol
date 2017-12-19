/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <rpatoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:37:55 by rpatoux           #+#    #+#             */
/*   Updated: 2017/05/23 18:40:56 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_motion(int x, int y, t_var *my)
{
	if (my->x_moove)
	{
		my->stay = 1;
		my->re = (float)(x + 550 - my->width) / 400;
		my->im = (float)(y + 450 - my->height) / 600;
	}
	return (1);
}

int		mouse_funct(int button, int x, int y, t_var *my)
{
	if ((button == 4 || button == 1) && my->zoom / 1.1 > 0)
	{
		if (my->maxi > 100)
			my->maxi -= 5;
		my->zoom /= 1.1;
		my->pos_x = (my->width / 2) - x + 25 + my->pos_x / 1.1;
		my->pos_y = (my->height / 2) - y + my->pos_y / 1.1;
	}
	if ((button == 5 || button == 2) && my->zoom * 1.1 < 1234648375)
	{
		my->maxi += 5;
		my->zoom *= 1.1;
		my->pos_x = (my->width / 2) - x + 25 + my->pos_x / 1.1;
		my->pos_y = (my->height / 2) - y + my->pos_y / 1;
	}
	return (1);
}

void	change_color_fractol(int keycode, t_var *my)
{
	if (keycode == 18)
		my->colore = 0x00FCFAE1;
	if (keycode == 19)
		my->colore = 0x00D51616;
	if (keycode == 20)
		my->colore = 0x00333333;
	if (keycode == 21)
		my->colore = 0x0016D5CF;
	if (keycode == 23)
		my->colore = 0x00FE6F01;
	if (keycode == 22)
		my->colore = 0x00D4FE01;
	if (keycode == 26)
		my->colore = 0x0052DF78;
	if (keycode == 28)
		my->colore = 0x00831AED;
	if (keycode == 25)
		my->colore = 0x00DED4D8;
}

void	key_funct_two(int keycode, t_var *my)
{
	if (keycode == 7)
		my->x_moove == 1 ? my->x_moove-- : my->x_moove++;
	if (keycode == 121 && my->zoom / 1.1 > 0)
	{
		my->maxi -= 3;
		my->zoom /= 1.1;
	}
	if (keycode == 126 || keycode == 125)
		my->h += keycode == 126 ? -30 - my->zoom * 30 : 30 + my->zoom * 30;
	if (keycode == 123 || keycode == 124)
		my->w += keycode == 124 ? 30 + my->zoom * 30 : -30 - my->zoom * 30;
}

int		key_funct(int keycode, t_var *my)
{
	ft_new_screen(my);
	change_color_fractol(keycode, my);
	key_funct_two(keycode, my);
	if (keycode == 36)
		ft_init_pos(my);
	if (keycode == 46)
		my->name = ft_strdup("Mandelbrot");
	if (keycode == 38)
		my->name = ft_strdup("Julia");
	if (keycode == 17)
		my->name = ft_strdup("Tricorn");
	if (keycode == 116 && my->zoom * 1.1 <= 1234648375)
	{
		my->maxi += 3;
		my->zoom *= 1.1;
	}
	if (keycode == 53)
	{
		free_all(my);
		exit(EXIT_SUCCESS);
	}
	return (1);
}
