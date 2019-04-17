/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:50:19 by amontano          #+#    #+#             */
/*   Updated: 2019/04/12 23:18:11 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"

static void	get_icons(t_img *icons[6], t_mlx *mlx)
{
	static int f = 1;

	if (f == 1)
	{
		f = 0;
		icons[BRUSH] = mlx->icon_brush;
		icons[LINE] = mlx->icon_line;
		icons[RECTANGLE] = mlx->icon_square;
		icons[ELLIPSE] = mlx->icon_ellipse;
		icons[BUCKET] = mlx->icon_bucket;
		icons[COLOR_PICK] = mlx->icon_eyedrop;
	}
}

int			render(t_mlx *mlx)
{
	t_img			*active_icon;
	int				mode;
	static t_img	*icons[6];

	get_icons(icons, mlx);
	mode = (mlx->mode >= 5) ? 5 : mlx->mode;
	active_icon = icons[mode];
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	if (mlx->color_gui_on)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->color_gui->img, 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->c_ui_p->img, \
		WIN_W - 128, 20);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->c_ui_s->img, \
		WIN_W - 128, 104);
	mlx_put_image_to_window(mlx->mlx, mlx->win, active_icon->img, \
		WIN_W - 128, 188);
	return (0);
}
