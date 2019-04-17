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

void	fill_brush_radius(t_mlx *mlx, int x, int y)
{
	int i;
	int k;
	int radius;

	radius = mlx->brush_size;
	i = -radius;
	while (i <= radius)
	{
		k = -radius;
		while (k <= radius)
		{
			img_set_pixel(mlx->img, x + i, y + k, mlx->color_current);
			k++;
		}
		i++;
	}
}
