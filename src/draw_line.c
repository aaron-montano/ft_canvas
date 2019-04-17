/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:59:27 by amontano          #+#    #+#             */
/*   Updated: 2019/04/14 19:59:40 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"

/*
**		A  --  D
**		|	   |
**		C  --  B
*/

void		draw_rectangle(t_mlx *mlx, t_point a, t_point b)
{
	t_point	c;
	t_point	d;

	c.x = a.x;
	c.y = b.y;
	d.x = b.x;
	d.y = a.y;
	draw_line(mlx, a, c);
	draw_line(mlx, a, d);
	draw_line(mlx, b, c);
	draw_line(mlx, b, d);
}

static void	line_helper(t_point *d, t_point *s, t_point p1, t_point p2)
{
	d->x = (int)ft_abs(p2.x - p1.x);
	d->y = (int)ft_abs(p2.y - p1.y);
	s->x = p1.x < p2.x ? 1 : -1;
	s->y = p1.y < p2.y ? 1 : -1;
}

void		draw_line(t_mlx *mlx, t_point p1, t_point p2)
{
	t_point	d;
	t_point	s;
	t_point	err;

	line_helper(&d, &s, p1, p2);
	err.x = (d.x > d.y ? d.x : -d.y) / 2;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		if (p1.x < 0 || p1.x >= WIN_W || p1.y < 0 || p1.y >= WIN_H || p2.x < 0 \
			|| p2.x >= WIN_W || p2.y < 0 || p2.y >= WIN_H)
			break ;
		fill_brush_radius(mlx, p1.x, p1.y);
		err.y = err.x;
		if (err.y > -d.x)
		{
			err.x -= d.y;
			p1.x += s.x;
		}
		if (err.y < d.y)
		{
			err.x += d.x;
			p1.y += s.y;
		}
	}
}
