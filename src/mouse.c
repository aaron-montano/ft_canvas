/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:12:59 by amontano          #+#    #+#             */
/*   Updated: 2019/03/06 21:56:48 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"
#include <stdio.h>

int hook_mouse_down(int button, int x, int y, t_mlx *mlx)
{
	if (y < 0)
		return (0);
	mlx->mouse->last_clicked_x = x;
	mlx->mouse->last_clicked_y = y;
	if (button == 1)
		mlx->color_current = mlx->color_1;
	if (button == 2)
		mlx->color_current = mlx->color_2;
	if (mlx->mode == 0)
		img_set_pixel(mlx->img, x, y, mlx->color_current);
	if (button < 4)
		mlx->mouse->is_down |= 1 << button;
	return (0);
}

int hook_mouse_up(int button, int x, int y, t_mlx *mlx)
{
	//printf("(%d , %d) mouse up\n", x, y);
	(void)x;
	(void)y;
	mlx->mouse->is_down &= ((mlx->mouse->is_down & 0x30) | ~(1 << button));
	return (0);
}

int hook_mouse_move(int x, int y, t_mlx *mlx)
{
	mlx->mouse->prev_x = mlx->mouse->x;
	mlx->mouse->prev_y = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mode == 0 && mlx->mouse->is_down)
		img_set_pixel(mlx->img, x, y, mlx->color_current);
	return (0);
}
