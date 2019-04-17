/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bucket.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 20:02:06 by amontano          #+#    #+#             */
/*   Updated: 2019/04/14 20:02:15 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"

int			color_at(char *img, int x, int y)
{
	return (*(int *)(img + (x + (y * WIN_W)) * 4));
}

void		scan_routine(t_mlx *mlx, int x, int y, t_queue *q)
{
	char	*img;
	int		tc;

	img = mlx->img->ptr;
	tc = *(int *)(img + ((x + (y * WIN_W)) * 4));
	*(int *)(img + ((x + (y * WIN_W)) * 4)) = mlx->color_current;
	if (x < WIN_W - 1 && color_at(img, x + 1, y) == tc)
		enqueue(q, (void *)new_point(x + 1, y));
	if (x > 0 && color_at(img, x - 1, y) == tc)
		enqueue(q, (void *)new_point(x - 1, y));
	if (y < WIN_H - 1 && color_at(img, x, y - 1) == tc)
		enqueue(q, (void *)new_point(x, y + 1));
	if (y > 0 && color_at(img, x, y - 1) == tc)
		enqueue(q, (void *)new_point(x, y - 1));
	if (x < WIN_W - 1 && y < WIN_H - 2 && color_at(img, x + 1, y + 1) == tc)
		enqueue(q, (void *)new_point(x + 1, y + 1));
	if (x < WIN_W - 1 && y > 0 && color_at(img, x + 1, y - 1) == tc)
		enqueue(q, (void *)new_point(x + 1, y - 1));
	if (x > 0 && y < WIN_H - 1 && color_at(img, x - 1, y + 1) == tc)
		enqueue(q, (void *)new_point(x - 1, y + 1));
	if (x > 0 && y > 0 && color_at(img, x - 1, y - 1) == tc)
		enqueue(q, (void *)new_point(x - 1, y - 1));
}

void		flood_fill(t_mlx *mlx, int tc, int cc, t_point *start)
{
	t_queue	*q;
	t_point	*spot;
	void	*v;
	int		x;
	int		y;

	if (tc == cc)
		return ;
	q = queue_init();
	enqueue(q, (void *)new_point(start->x, start->y));
	while (!queue_isempty(q))
	{
		v = q->first->content;
		spot = (t_point *)v;
		x = spot->x;
		y = spot->y;
		if (color_at(mlx->img->ptr, x, y) == tc)
			scan_routine(mlx, x, y, q);
		if ((v = dequeue(q)))
		{
			spot = (t_point *)v;
			free(spot);
		}
	}
	free(q);
}

void		draw_bucket(t_mlx *mlx, int x, int y)
{
	int		target_color;
	t_point	*start;

	start = new_point(x, y);
	target_color = color_at(mlx->img->ptr, x, y);
	flood_fill(mlx, target_color, mlx->color_current, start);
	if (start)
		free(start);
}
