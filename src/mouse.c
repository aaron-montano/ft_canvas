/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:12:59 by amontano          #+#    #+#             */
/*   Updated: 2019/03/07 11:58:28 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"
#include <stdio.h>

int	hook_mouse_down(int button, int x, int y, t_mlx *mlx)
{
	if (y < 0)
		return (0);
	mlx->mouse->last_clicked_x = x;
	mlx->mouse->last_clicked_y = y;
	if (button == 1)
		mlx->color_current = mlx->color_1;
	if (button == 2)
		mlx->color_current = mlx->color_2;
	if (button < 3 && mlx->mode == 0)
	{
		fill_brush_radius(mlx->img, mlx->mouse->prev_x, mlx->mouse->prev_y, \
														mlx->color_current, 5);
		fill_brush_radius(mlx->img, x, y, mlx->color_current, 5);
	}
	if (button < 4)
		mlx->mouse->is_down |= 1 << button;
	mlx->action_status = 1;
	return (0);
}

int	hook_mouse_up(int button, int x, int y, t_mlx *mlx)
{
	mlx->mouse->is_down &= ((mlx->mouse->is_down & 0x30) | ~(1 << button));
	if (mlx->mode == 0 && button == 2)
		mlx->color_current = mlx->color_1;
	else if (mlx->mode == 0 && button == 1)
		mlx->color_current = mlx->color_2;
	if (mlx->mode == 1)
		draw_line(mlx, mlx->mouse->last_clicked_x, \
					mlx->mouse->last_clicked_y, x, y);
	else if (mlx->mode == 2)
		draw_rectangle(mlx, mlx->mouse->last_clicked_x, \
						mlx->mouse->last_clicked_y, x, y);
	update_buf(mlx);
	return (0);
}

int	hook_mouse_move(int x, int y, t_mlx *mlx)
{
	mlx->mouse->prev_x = mlx->mouse->x;
	mlx->mouse->prev_y = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mode == 0 && mlx->mouse->is_down > 0 && mlx->mouse->is_down < 7)
	{
		fill_brush_radius(mlx->img, mlx->mouse->prev_x, mlx->mouse->prev_y, \
						mlx->color_current, 5);
		fill_brush_radius(mlx->img, x, y, mlx->color_current, 5);
	}
	return (0);
}
