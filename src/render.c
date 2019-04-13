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

int	render(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	if (mlx->color_gui_on)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->color_gui->img, 0, 0);
	return (0);
}
