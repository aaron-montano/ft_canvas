/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:26:46 by amontano          #+#    #+#             */
/*   Updated: 2019/04/13 00:16:16 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"

int				hook_close(void)
{
	exit(0);
}

void			error(char *str)
{
	ft_putendl(str);
	hook_close();
}

static void		default_values(t_mlx *mlx)
{
	fill_img(mlx->img, 0xe0e0e0, WIN_W, WIN_H);
	update_buf(mlx);
	mlx->color_1 = 0x000000;
	mlx->color_2 = 0xFF00FF;
	mlx->mode = BRUSH;
}

void			usage(void)
{
	ft_putstr("1\tBrush\n2\tLine\n3\tRectangle\n4\tEllipse\n5\tBucket\n");
	ft_putstr("6\tEyedrop\n\nSpace\tPallete Toggle\nNum0\tPallete Toggle\n\n");
	ft_putstr("W\tBrush Size Up\nNum+\tBrush Size Up\n");
	ft_putstr("S\tBrush Size Down\nNum+\tBrush Size Down\n\n");
	ft_putstr("Z\tUndo\nY\tRedo\n\\\tReset\nESC\tExit\n");
}

int				main(void)
{
	t_mlx *mlx;

	usage();
	if (!(mlx = init()))
		error("mlx failed to init");
	default_values(mlx);
	fill_img(mlx->c_ui_p, mlx->color_1, 64, 64);
	fill_img(mlx->c_ui_s, mlx->color_2, 64, 64);
	mlx_hook(mlx->win, 3, 0, hook_key_up, mlx);
	mlx_hook(mlx->win, 2, 0, hook_key_down, mlx);
	mlx_hook(mlx->win, 4, 0, hook_mouse_down, mlx);
	mlx_hook(mlx->win, 5, 0, hook_mouse_up, mlx);
	mlx_hook(mlx->win, 6, 0, hook_mouse_move, mlx);
	mlx_hook(mlx->win, 17, 0, hook_close, mlx);
	mlx_loop_hook(mlx->mlx, &render, mlx);
	mlx_loop(mlx->mlx);
	stack_dispose(mlx, mlx->buf);
	stack_dispose(mlx, mlx->redo_buf);
	mlx_dispose(mlx);
	return (0);
}
