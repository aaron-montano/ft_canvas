/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 08:47:14 by amontano          #+#    #+#             */
/*   Updated: 2019/04/07 20:44:09 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"
#include <stdio.h>

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

void	get_ellipse_params(t_mlx *mlx, int x1, int y1, int x2, int y2)
{
	int		center_x = (x1 + x2) / 2;
	int		center_y = (y1 + y2) / 2;
	int		radius_x = ft_abs(x2 - x1) / 2;
	int		radius_y = ft_abs(y2 - y1) / 2;

	draw_ellipse(mlx, center_x, center_y, radius_x, radius_y);
}

void			draw_ellipse(t_mlx *mlx, int cx, int cy, int rx, int ry)
{
	double		d1, d2, dx, dy;
	//int x, y;
	double x, y;

	x = 0;
	y = ry;

	//region 1 decision param
	d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;
	//draw region 1
	while (dx < dy)
	{
		fill_brush_radius(mlx->img, x + cx, y + cy, mlx->color_current,5);
		fill_brush_radius(mlx->img, -x + cx, y + cy, mlx->color_current,5);
		fill_brush_radius(mlx->img, x + cx, -y + cy, mlx->color_current,5);
		fill_brush_radius(mlx->img, -x + cx, -y + cy, mlx->color_current,5);
        if (d1 < 0) { 
            x++; 
            dx = dx + (2 * ry * ry); 
            d1 = d1 + dx + (ry * ry); 
        } 
        else { 
            x++; 
            y--; 
            dx = dx + (2 * ry * ry); 
            dy = dy - (2 * rx * rx); 
            d1 = d1 + dx - dy + (ry * ry); 
        } 
	}
	//region 2 decision param
	d2 = ((ry * ry) * (((double)x + 0.5) * ((double)x + 0.5))) 
			+ ((rx * rx) * (((double)y - 1) * ((double)y - 1))) 
			- (rx * rx * ry * ry);
	if (d2 > 0)
		d2 = sqrt(d2);
	while (y >= 0)
	{
		fill_brush_radius(mlx->img, x + cx, y + cy, mlx->color_current,5);
		fill_brush_radius(mlx->img, -x + cx, y + cy, mlx->color_current,5);
		fill_brush_radius(mlx->img, x + cx, -y + cy, mlx->color_current,5);
		fill_brush_radius(mlx->img, -x + cx, -y + cy, mlx->color_current,5);
		if (d2 > 0) {

			y--; 
			dy = dy - (2 * rx * rx); 
			d2 = d2 + (rx * rx) - dy; 
		} 
		else {
			y--; 
			x++; 
			dx = dx + (2 * ry * ry); 
			dy = dy - (2 * rx * rx); 
			d2 = d2 + dx - dy + (rx * rx); 
		} 
	}

}

