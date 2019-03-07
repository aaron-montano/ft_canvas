/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:26:46 by amontano          #+#    #+#             */
/*   Updated: 2019/03/06 21:51:47 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"

int	hook_close(void)
{
	exit(0);
}

void error(char *str)
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
	if (mlx->mouse)
		ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx	*init(void)
{
	t_mlx *mlx;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx = mlx_init()) \
			|| (!(mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, \
						"ft_canvas -- amontano")))					\
			|| (!(mlx->img = new_img(mlx)))							\
			|| (!(mlx->mouse = (t_mouse *)ft_memalloc(sizeof(t_mouse))))	\
		)
	{
		ft_putendl("mlx falied to init");
		return (mlx_dispose(mlx));
	}
	return (mlx);
}

int main(void)
{
	t_mlx *mlx;
	
	if (!(mlx = init()))
		error("mlx failed to init");
	//mlx_hook(mlx->win, 2, 0, hook_key_down, mlx);
	//mlx_hook(mlx->win, 3, 0, hook_key_up, mlx);
	
	mlx->color_1 = 0xFFFF00;
	mlx->color_2 = 0xFF00FF;
	mlx_hook(mlx->win, 4, 0, hook_mouse_down, mlx);
	mlx_hook(mlx->win, 5, 0, hook_mouse_up, mlx);
	mlx_hook(mlx->win, 6, 0, hook_mouse_move, mlx);
	mlx_hook(mlx->win, 17, 0, hook_close, mlx);
	mlx_loop_hook(mlx->mlx, &render, mlx);
	mlx_loop(mlx->mlx);
}