/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:35:00 by amontano          #+#    #+#             */
/*   Updated: 2019/04/07 00:03:29 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CANVAS_H
# define FT_CANVAS_H

# include <math.h>
# include <stdlib.h>

# include "libft.h"
//# include "keys.h"
# include "mlx.h"

# define WIN_W 1600
# define WIN_H 900

typedef struct	s_mouse
{
	double		x;
	double		y;
	double		prev_x;
	double		prev_y;
	double		last_clicked_x;
	double		last_clicked_y;
	int			is_down;
}				t_mouse;

typedef struct	s_img
{
	void		*img;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_mouse		*mouse;

	int			color_1;
	int			color_2;
	int			color_current;
	t_stack		*buf;
	t_stack		*redo_buf;
	int			action_status;
	int			mode; // 0-brush 1-line 2-rectangle 3-ellipse

}				t_mlx;

/*
** img.c
*/
void			img_set_pixel(t_img *img, int x, int y, int color);
void			clear_img(t_img *img);
t_img			*del_img(t_mlx *mlx, t_img *img);
t_img			*new_img(t_mlx *mlx);
void			fill_img(t_img *img, int color);

/*
** mouse.c
*/
int 			hook_mouse_down(int button, int x, int y, t_mlx *mlx);
int 			hook_mouse_up(int button, int x, int y, t_mlx *mlx);
int 			hook_mouse_move(int x, int y, t_mlx *mlx);

/*
** main.c
*/
t_mlx			*init(void);
t_mlx			*mlx_dispose(t_mlx *mlx);
void 			error(char *str);
int				hook_close(void);

/*
** render.c
*/
int				render(t_mlx *mlx);


/*
** keyboard.c
*/
int 			hook_key_up(int button, t_mlx *mlx);

/*
** draw.c
*/
void 			fill_brush_radius(t_img *img, int x, int y, int color, int radius);
void			draw_line(t_mlx *mlx, int x1, int y1, int x2, int y2);
void			draw_rectangle(t_mlx *mlx, int x1, int x2, int y1, int y2);

/*
** frame_buffer.c
*/
void			undo(t_mlx *mlx);
void			redo(t_mlx *mlx);
void			stack_dispose(t_mlx *mlx, t_stack *stack);
void			update_buf(t_mlx *mlx);
void			set_mlx_img_ptr(t_mlx *mlx);
#endif
