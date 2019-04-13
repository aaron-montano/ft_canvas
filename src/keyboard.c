/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 23:23:02 by amontano          #+#    #+#             */
/*   Updated: 2019/04/13 00:28:36 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"
#include "keys.h"

int	hook_key_up(int button, t_mlx *mlx)
{
	if (button == KEY_1)
		mlx->mode = BRUSH;
	if (button == KEY_2)
		mlx->mode = LINE;
	if (button == KEY_3)
		mlx->mode = RECTANGLE;
	if (button == KEY_4)
		mlx->mode = ELLIPSE;
	if (button == KEY_5)
		mlx->mode = BUCKET;
	if (button == KEY_6)
		mlx->mode = COLOR_PICK;
	if (button == KEY_Z)
		undo(mlx);
	if (button == KEY_Y)
		redo(mlx);
	if (button == 42)
	{
		fill_img(mlx->img, 0xe0e0e0);
		update_buf(mlx);
	}
	if (button == KEY_SPACE)
		!mlx->color_gui_on ? deploy_color_gui(mlx) : hide_color_gui(mlx);
	return (0);
}

int hook_key_down(int button, t_mlx *mlx)
{
	if (button == KEY_NUM_PLUS && mlx->brush_size < 43)
		mlx->brush_size++;
	if (button == KEY_NUM_MINUS && mlx->brush_size > 0)
		mlx->brush_size--;
	if (button == KEY_ESC)
		hook_close();
	return (0);
}
