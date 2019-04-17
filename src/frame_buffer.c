/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 11:08:37 by amontano          #+#    #+#             */
/*   Updated: 2019/04/07 00:03:27 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"

void	update_buf(t_mlx *mlx)
{
	t_img	*n_img;
	void	*v;

	v = (void *)mlx->img;
	n_img = new_img(mlx, WIN_W, WIN_H);
	n_img->ptr = (char *)ft_memcpy(n_img->ptr, mlx->img->ptr, \
			WIN_H * WIN_W * 4);
	push(mlx->buf, v);
	if (!stack_isempty(mlx->redo_buf))
		stack_dispose(mlx, mlx->redo_buf);
	mlx->img = n_img;
}

void	undo(t_mlx *mlx)
{
	if (mlx->buf->top->next)
	{
		push(mlx->redo_buf, pop(mlx->buf));
		set_mlx_img_ptr(mlx);
	}
}

void	redo(t_mlx *mlx)
{
	if (!stack_isempty(mlx->redo_buf))
	{
		push(mlx->buf, pop(mlx->redo_buf));
		set_mlx_img_ptr(mlx);
	}
}

void	set_mlx_img_ptr(t_mlx *mlx)
{
	t_img	*i;

	if ((i = (t_img *)mlx->buf->top->content))
		mlx->img->ptr = (char *)ft_memcpy(mlx->img->ptr, i->ptr, \
				WIN_H * WIN_W * 4);
}

void	stack_dispose(t_mlx *mlx, t_stack *stack)
{
	void	*v;
	t_img	*i;

	while (!stack_isempty(stack))
	{
		v = pop(stack);
		if ((i = (t_img *)v))
			del_img(mlx, i);
	}
}
