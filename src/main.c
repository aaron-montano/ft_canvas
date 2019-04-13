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

int		hook_close(void)
{
	exit(0);
}

void	error(char *str)
{
	ft_putendl(str);
	hook_close();
}

t_mlx	*mlx_dispose(t_mlx *mlx)
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
	return (NULL);
}

t_mlx	*init(void)
{
	t_mlx *mlx;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx = mlx_init())											\
			|| (!(mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, 		\
						"ft_canvas -- amontano")))							\
			|| (!(mlx->img = new_img(mlx, WIN_W, WIN_H)))					\
			|| (!(mlx->mouse = (t_mouse *)ft_memalloc(sizeof(t_mouse))))	\
			|| (!(mlx->buf = stack_init()))									\
			|| (!(mlx->redo_buf = stack_init()))							\
			|| (!(mlx->color_gui = new_img(mlx, PALLET_W, PALLET_H)))		\
			|| (!(mlx->color_gui->img = \
					mlx_xpm_file_to_image(mlx->mlx, PALLET, &mlx->pw, &mlx->ph)))
		)
	{
		ft_putendl("mlx falied to init");
		return (mlx_dispose(mlx));
	}
	mlx->color_gui->ptr = \
		mlx_get_data_addr(mlx->color_gui->img, &mlx->color_gui->bpp, &mlx->color_gui->stride, &mlx->color_gui->endian);
	mlx->color_gui->bpp /= 8;
	mlx->brush_size = 1;
	mlx->color_gui_on = 0;
	return (mlx);
}

int		main(void)
{
	t_mlx *mlx;

	if (!(mlx = init()))
		error("mlx failed to init");
	clear_img(mlx->img);
	fill_img(mlx->img, 0xe0e0e0);
	update_buf(mlx);
	mlx->color_1 = 0x000000;
	mlx->color_2 = 0xFF00FF;
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
	return (0);
}
