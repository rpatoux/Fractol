/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <rpatoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:09:46 by rpatoux           #+#    #+#             */
/*   Updated: 2017/05/19 15:01:14 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	free_all(t_var *my)
{
	mlx_destroy_image(my->mlx, my->img);
	my->mlx = NULL;
	my->win = NULL;
	my->img = NULL;
	free(my->name);
	my->name = NULL;
	free(my);
	my = NULL;
}

void	ft_new_screen(t_var *my)
{
	mlx_destroy_image(my->mlx, my->img);
	my->img = mlx_new_image(my->mlx, my->width, my->height);
	my->data = mlx_get_data_addr(my->img, &my->bpp,
	&my->sl, &my->endian);
}

void	ft_init_pos(t_var *my)
{
	my->zoom = 1;
	my->colore = 0x0081A9A4;
	my->h = 0;
	my->w = 0;
	my->pos_x = 0;
	my->pos_y = 0;
	my->maxi = 100;
	my->x_moove = 0;
	my->y_moove = 0;
}
