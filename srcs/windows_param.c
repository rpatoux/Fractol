/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <rpatoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:36:28 by rpatoux           #+#    #+#             */
/*   Updated: 2017/05/19 15:00:55 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				ft_init(t_var *my)
{
	my->x_moove = 0;
	my->h = 0;
	my->w = 0;
	my->maxi = 100;
	my->pos_x = 0;
	my->pos_y = 0;
	my->zoom = 1;
	my->colore = 0x0081A9A4;
	my->width = 1300;
	my->height = 1300;
	my->bpp = 24;
	my->endian = 1;
	my->sl = my->width * (my->bpp / 8);
	return (1);
}

static void		write_info_screen_bis(t_var *my)
{
	mlx_string_put(my->mlx, my->win, 21, 6, 0xFF0000,
		"Touches disponibles : ");
	mlx_string_put(my->mlx, my->win, 21, 31, 0xFFFFFF, "J   -> Julia");
	mlx_string_put(my->mlx, my->win, 21, 56, 0xFFFFFF, "M   -> Mandelbrot");
	mlx_string_put(my->mlx, my->win, 21, 81, 0xFFFFFF, "T   -> Tricorn");
	mlx_string_put(my->mlx, my->win, 21, 131, 0xFFFFFF,
			"Fleche gauche -> Gauche");
	mlx_string_put(my->mlx, my->win, 21, 156, 0xFFFFFF,
			"Fleche droite -> Droite");
	mlx_string_put(my->mlx, my->win, 21, 181, 0xFFFFFF,
			"Fleche bas    -> Bas");
	mlx_string_put(my->mlx, my->win, 21, 206, 0xFFFFFF,
			"Fleche haut   -> Haut");
	mlx_string_put(my->mlx, my->win, 21, 256, 0xFFFFFF,
			"De 1 a 9              -> Couleur");
	mlx_string_put(my->mlx, my->win, 21, 281, 0xFFFFFF,
			"Page up / Molette / clic gauche     -> Zoomer");
	mlx_string_put(my->mlx, my->win, 21, 306, 0xFFFFFF,
			"Page down / Molette / clic droit   -> Dezoomer");
	mlx_string_put(my->mlx, my->win, 21, 331, 0xFFFFFF,
			"Entrer                -> Reset");
}

static void		write_info_screen(t_var *my)
{
	mlx_string_put(my->mlx, my->win, 20, 5, 0xFF0000,
		"Touches disponibles : ");
	mlx_string_put(my->mlx, my->win, 20, 30, 0x000000, "J   -> Julia");
	mlx_string_put(my->mlx, my->win, 20, 55, 0x000000, "M   -> Mandelbrot");
	mlx_string_put(my->mlx, my->win, 20, 80, 0x000000, "T   -> Tricorn");
	mlx_string_put(my->mlx, my->win, 20, 130, 0x000000,
			"Fleche gauche -> Gauche");
	mlx_string_put(my->mlx, my->win, 20, 155, 0x000000,
			"Fleche droite -> Droite");
	mlx_string_put(my->mlx, my->win, 20, 180, 0x000000,
			"Fleche bas    -> Bas");
	mlx_string_put(my->mlx, my->win, 20, 205, 0x000000,
			"Fleche haut   -> Haut");
	mlx_string_put(my->mlx, my->win, 20, 255, 0x000000,
			"De 1 a 9              -> Couleur");
	mlx_string_put(my->mlx, my->win, 20, 280, 0x000000,
			"Page up / Molette / clic gauche     -> Zoomer");
	mlx_string_put(my->mlx, my->win, 20, 305, 0x000000,
			"Page down / Molette / clic droit   -> Dezoomer");
	mlx_string_put(my->mlx, my->win, 20, 330, 0x000000,
			"Entrer                -> Reset");
}

static void		write_data_screen(t_var *my)
{
	mlx_string_put(my->mlx, my->win, my->width - 250, my->height - 25, 0x000000,
		"Fractale =");
	mlx_string_put(my->mlx, my->win, my->width - 130, my->height - 25, 0x000000,
		my->name);
	if (ft_strcmp(my->name, "Julia") == 0)
	{
		mlx_string_put(my->mlx, my->win, 50, my->height - 25, 0x000000,
			"Press X for Moove or Stop Julia");
		mlx_string_put(my->mlx, my->win, 51, my->height - 25, 0xFFFFFF,
			"Press X for Moove or Stop Julia");
	}
}

void			write_screen(t_var *my)
{
	write_info_screen(my);
	write_info_screen_bis(my);
	write_data_screen(my);
}
