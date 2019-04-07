/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 23:23:02 by amontano          #+#    #+#             */
/*   Updated: 2019/04/06 21:53:43 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"
#include "keys.h"

int	hook_key_up(int button, t_mlx *mlx)
{
	if (button == KEY_ESC)
		hook_close();
	if (button == KEY_1)
		mlx->mode = 0;
	if (button == KEY_2)
		mlx->mode = 1;
	if (button == KEY_3)
		mlx->mode = 2;
	if (button == KEY_Z)
		undo(mlx);
	if (button == KEY_Y)
		redo(mlx);
	if (button == 42)
	{
		fill_img(mlx->img, 0xe0e0e0);
		update_buf(mlx);
	}
	return (0);
}
