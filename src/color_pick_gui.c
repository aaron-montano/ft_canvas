/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pick_gui.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:50:16 by amontano          #+#    #+#             */
/*   Updated: 2019/04/11 20:50:18 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"
# include <stdio.h>
void    deploy_color_gui(t_mlx *mlx)
{
    mlx->color_gui_on = 1;
    if (mlx->mode != COLOR_PICK)
        mlx->prevMode = mlx->mode;
    mlx->mode = COLOR_PICK;
}

void    hide_color_gui(t_mlx *mlx)
{
    mlx->mode = mlx->prevMode;
    mlx->color_gui_on = 0;
}

void    color_pick(t_mlx *mlx, int x, int y, int button)
{
    char *img;
    int color;

    img = mlx->color_gui->ptr;
    if (x > 0 && x < PALLET_W - 1 && y > 0 && y < PALLET_H - 1)
    {
        color = *(int *)(img + (x + (y * -(PALLET_W - WIN_W)) * 4 ));
        color &= 0xFFFFFF;
        printf("x:%d, y:%d\n", x, y);
        printf("%x\n\n", color);
    }
    if (button == MOUSE_1)
        mlx->color_1 = color;
    else if (button == MOUSE_2)
        mlx->color_2 = color;
}
