/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:29:29 by amontano          #+#    #+#             */
/*   Updated: 2019/04/14 14:29:48 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"

static void		dispose_icons(t_mlx *mlx)
{
	if (mlx->icon_brush)
		del_img(mlx, mlx->icon_brush);
	if (mlx->icon_line)
		del_img(mlx, mlx->icon_line);
	if (mlx->icon_square)
		del_img(mlx, mlx->icon_square);
	if (mlx->icon_ellipse)
		del_img(mlx, mlx->icon_ellipse);
	if (mlx->icon_bucket)
		del_img(mlx, mlx->icon_bucket);
	if (mlx->icon_eyedrop)
		del_img(mlx, mlx->icon_eyedrop);
}

t_mlx			*mlx_dispose(t_mlx *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->img)
		del_img(mlx, mlx->img);
	if (mlx->color_gui)
		del_img(mlx, mlx->color_gui);
	if (mlx->mouse)
		ft_memdel((void **)&mlx);
	if (mlx->buf)
		stack_dispose(mlx, mlx->buf);
	if (mlx->redo_buf)
		stack_dispose(mlx, mlx->redo_buf);
	if (mlx->c_ui_p)
		del_img(mlx, mlx->c_ui_p);
	if (mlx->c_ui_s)
		del_img(mlx, mlx->c_ui_s);
	dispose_icons(mlx);
	return (NULL);
}

t_mlx			*init(void)
{
	t_mlx *mlx;

	if ((mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		if (!(mlx->mlx = mlx_init())										\
				|| (!(mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, 	\
							"ft_canvas -- amontano")))						\
				|| (!(mlx->img = new_img(mlx, WIN_W, WIN_H)))				\
				|| (!(mlx->mouse = (t_mouse *)ft_memalloc(sizeof(t_mouse))))\
				|| (!(mlx->buf = stack_init()))								\
				|| (!(mlx->redo_buf = stack_init()))						\
				|| (!(mlx->color_gui = xpm_image(PALLET, mlx)))				\
				|| (!(mlx->c_ui_p = new_img(mlx, 64, 64)))					\
				|| (!(mlx->c_ui_s = new_img(mlx, 64, 64)))					\
				|| (!(mlx->icon_brush = xpm_image(ICON_BRUSH, mlx)))		\
				|| (!(mlx->icon_line = xpm_image(ICON_LINE, mlx)))			\
				|| (!(mlx->icon_square = xpm_image(ICON_SQUARE, mlx)))		\
				|| (!(mlx->icon_ellipse = xpm_image(ICON_ELLIPSE, mlx)))	\
				|| (!(mlx->icon_bucket = xpm_image(ICON_BUCKET, mlx)))		\
				|| (!(mlx->icon_eyedrop = xpm_image(ICON_EYEDROP, mlx))))
		{
			ft_putendl("mlx falied to init");
			return (mlx_dispose(mlx));
		}
	return (mlx);
}
