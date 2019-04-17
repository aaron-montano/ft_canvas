/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pick_gui.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:50:16 by amontano          #+#    #+#             */
/*   Updated: 2019/04/13 00:32:05 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"

void	deploy_color_gui(t_mlx *mlx)
{
	mlx->color_gui_on = 1;
	if (mlx->mode != COLOR_PICK_GUI)
		mlx->prev_mode = mlx->mode;
	mlx->mode = COLOR_PICK_GUI;
}

void	hide_color_gui(t_mlx *mlx)
{
	mlx->mode = mlx->prev_mode;
	mlx->color_gui_on = 0;
}

void	color_pick_gui(t_mlx *mlx, int x, int y, int button)
{
	char	*img;
	int		color;
	int		pos;

	if (x > 0 && x < PALLET_W && y > 0 && y < PALLET_H)
	{
		img = mlx->color_gui->ptr;
		mlx->mode = COLOR_PICK_GUI;
		pos = (x + y * PALLET_W) * 4;
		color = *(int *)(img + pos);
		if (button == MOUSE_1)
		{
			if (mlx->color_1 != color)
				fill_img(mlx->c_ui_p, color, 64, 64);
			mlx->color_1 = color;
		}
		else if (button == MOUSE_2)
		{
			if (mlx->color_2 != color)
				fill_img(mlx->c_ui_s, color, 64, 64);
			mlx->color_2 = color;
		}
	}
	else
		hide_color_gui(mlx);
}

void	color_pick(t_mlx *mlx, int x, int y, int button)
{
	char	*img;
	int		color;
	int		pos;

	if (x > 0 && x < WIN_W && y > 0 && y < WIN_H)
	{
		img = mlx->img->ptr;
		mlx->mode = COLOR_PICK;
		pos = (x + y * WIN_W) * 4;
		color = *(int *)(img + pos);
		if (button == MOUSE_1)
		{
			if (mlx->color_1 != color)
				fill_img(mlx->c_ui_p, color, 64, 64);
			mlx->color_1 = color;
		}
		else if (button == MOUSE_2)
		{
			if (mlx->color_2 != color)
				fill_img(mlx->c_ui_s, color, 64, 64);
			mlx->color_2 = color;
		}
	}
}
