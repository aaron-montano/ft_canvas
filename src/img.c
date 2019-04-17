/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:54:21 by amontano          #+#    #+#             */
/*   Updated: 2019/04/12 22:27:01 by amontano         ###   ########.fr       */
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

t_img	*new_img(t_mlx *mlx, int w, int h)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
		return (NULL);
	if ((img->img = mlx_new_image(mlx->mlx, w, h)) == NULL)
		return (del_img(mlx, img));
	img->ptr = \
		mlx_get_data_addr(img->img, &img->bpp, &img->stride, &img->endian);
	img->bpp /= 8;
	img->ht = h;
	img->wd = w;
	return (img);
}

void	img_set_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= img->wd || y < 0 || y >= img->ht)
		return ;
	*(int *)(img->ptr + ((x + (y * img->wd)) * img->bpp)) = color;
}

void	fill_img(t_img *img, int color, int wd, int ht)
{
	int	x;
	int	y;

	x = -1;
	while (++x < wd)
	{
		y = -1;
		while (++y < ht)
			img_set_pixel(img, x, y, color);
	}
}

t_img	*xpm_image(char *xpm, t_mlx *mlx)
{
	t_img	*img;

	if ((img = ft_memalloc(sizeof(t_img))) == NULL)
		return (NULL);
	if ((img->img = mlx_xpm_file_to_image(mlx->mlx, xpm,
					&img->wd, &img->ht)) == NULL)
		return (del_img(mlx, img));
	img->ptr = mlx_get_data_addr(img->img, &img->bpp,
			&img->stride, &img->endian);
	img->bpp /= 8;
	img->wd = img->stride / img->bpp;
	img->ht = img->stride / img->bpp;
	return (img);
}
