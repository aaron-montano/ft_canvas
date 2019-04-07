/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:54:21 by amontano          #+#    #+#             */
/*   Updated: 2019/03/07 12:28:48 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"

t_img	*del_img(t_mlx *mlx, t_img *img)
{
	if (img)
	{
		if (img->img)
			mlx_destroy_image(mlx->mlx, img->img);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

void	clear_img(t_img *img)
{
	ft_bzero(img->ptr, WIN_W * WIN_H * img->bpp);
}

t_img	*new_img(t_mlx *mlx)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
		return (NULL);
	if ((img->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H)) == NULL)
		return (del_img(mlx, img));
	img->ptr = \
		mlx_get_data_addr(img->img, &img->bpp, &img->stride, &img->endian);
	img->bpp /= 8;
	return (img);
}

void	img_set_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	*(int *)(img->ptr + ((x + (y * WIN_W)) * img->bpp)) = color;
}

void	fill_img(t_img *img, int color)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN_W)
	{
		y = -1;
		while (++y < WIN_H)
			img_set_pixel(img, x, y, color);
	}
}
