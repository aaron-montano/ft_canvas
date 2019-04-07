/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 08:47:14 by amontano          #+#    #+#             */
/*   Updated: 2019/03/07 10:18:17 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"

void	fill_brush_radius(t_img *img, int x, int y, int color, int radius)
{
	int	i;
	int	k;

	i = -radius;
	while (i <= radius)
	{
		k = -radius;
		while (k <= radius)
		{
			img_set_pixel(img, x + i, y + k, color);
			k++;
		}
		i++;
	}
}

void	draw_line(t_mlx *mlx, int x1, int y1, int x2, int y2)
{
	int dy;
	int dx;
	int sx;
	int	sy;
	int err;
	int err2;

	dx = (int)abs(x2 - x1);
	dy = (int)abs(y2 - y1);
	sx = x1 < x2 ? 1 : -1;
	sy = y1 < y2 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (x1 != x2 || y1 != y2)
	{
		if (x1 < 0 || x1 >= WIN_W || y1 < 0 || y1 >= WIN_H \
			|| x2 < 0 || x2 >= WIN_W || y2 < 0 || y2 >= WIN_H)
			break ;
		fill_brush_radius(mlx->img, x1, y1, mlx->color_current, 5);
		err2 = err;
		if (err2 > -dx)
		{
			err -= dy;
			x1 += sx;
		}
		if (err2 < dy)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void	draw_rectangle(t_mlx *mlx, int x1, int y1, int x2, int y2)
{
	draw_line(mlx, x1, y1, x1, y2);
	draw_line(mlx, x1, y1, x2, y1);
	draw_line(mlx, x2, y2, x2, y1);
	draw_line(mlx, x2, y2, x1, y2);
}
