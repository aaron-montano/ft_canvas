/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:00:48 by amontano          #+#    #+#             */
/*   Updated: 2019/04/14 15:01:27 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"

void	get_ellipse_params(t_mlx *mlx, int x2, int y2)
{
	t_point p;
	t_point c;
	t_point r;

	p.x = mlx->mouse->last_clicked_x;
	p.y = mlx->mouse->last_clicked_y;
	c.x = (p.x + x2) / 2;
	c.y = (p.y + y2) / 2;
	r.x = ft_abs(x2 - p.x) / 2;
	r.y = ft_abs(y2 - p.y) / 2;
	draw_ellipse(mlx, c, r);
}

void	draw_arc_ref(t_mlx *mlx, t_point p, t_point c)
{
	fill_brush_radius(mlx, p.x + c.x, p.y + c.y);
	fill_brush_radius(mlx, -p.x + c.x, p.y + c.y);
	fill_brush_radius(mlx, p.x + c.x, -p.y + c.y);
	fill_brush_radius(mlx, -p.x + c.x, -p.y + c.y);
}

void	ellipse_1(t_mlx *mlx, t_ellipse *e, t_point c, t_point r)
{
	while (e->m.dx < e->m.dy)
	{
		draw_arc_ref(mlx, e->pos, c);
		if (e->det.dx < 0)
		{
			e->m.dx = e->m.dx + (2 * r.y * r.y);
			e->det.dx = e->det.dx + e->m.dx + (r.y * r.y);
		}
		else
		{
			e->pos.y--;
			e->m.dx = e->m.dx + (2 * r.y * r.y);
			e->m.dy = e->m.dy - (2 * r.x * r.x);
			e->det.dx = e->det.dx + e->m.dx - e->m.dy + (r.y * r.y);
		}
		e->pos.x++;
	}
}

void	ellipse_2(t_mlx *mlx, t_ellipse *e, t_point c, t_point r)
{
	while (e->pos.y >= 0)
	{
		draw_arc_ref(mlx, e->pos, c);
		if (e->det.dy > 0)
		{
			e->m.dy = e->m.dy - (2 * r.x * r.x);
			e->det.dy = e->det.dy + (r.x * r.x) - e->m.dy;
		}
		else
		{
			e->pos.x++;
			e->m.dx = e->m.dx + (2 * r.y * r.y);
			e->m.dy = e->m.dy - (2 * r.x * r.x);
			e->det.dy = e->det.dy + e->m.dx - e->m.dy + (r.x * r.x);
		}
		e->pos.y--;
	}
}

void	draw_ellipse(t_mlx *mlx, t_point c, t_point r)
{
	t_ellipse e;

	e.pos.x = 0;
	e.pos.y = r.y;
	e.det.dx = (r.y * r.y) - (r.x * r.x * r.y) + (0.25 * r.x * r.x);
	e.m.dx = 2 * r.y * r.y * e.pos.x;
	e.m.dy = 2 * r.x * r.x * e.pos.y;
	ellipse_1(mlx, &e, c, r);
	e.det.dy = \
		((r.y * r.y) * (((double)e.pos.x + 0.5) * ((double)e.pos.x + 0.5))) \
		+ ((r.x * r.x) * (((double)e.pos.y - 1) * ((double)e.pos.y - 1)))	\
		- (r.x * r.x * r.y * r.y);
	if (e.det.dy > 0)
		e.det.dy = sqrt(e.det.dy);
	ellipse_2(mlx, &e, c, r);
}
