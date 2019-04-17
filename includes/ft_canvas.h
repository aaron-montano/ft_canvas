/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:35:00 by amontano          #+#    #+#             */
/*   Updated: 2019/04/13 00:27:14 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CANVAS_H
# define FT_CANVAS_H

# include <math.h>
# include <stdlib.h>

# include "libft.h"
# include "keys.h"
# include "mlx.h"

# define WIN_W 1600
# define WIN_H 900
# define BRUSH 0
# define LINE 1
# define RECTANGLE 2
# define ELLIPSE 3
# define BUCKET 4
# define COLOR_PICK	5
# define COLOR_PICK_GUI 6
# define PALLET "./icons/colormap_hex.xpm"
# define ICON_BRUSH	"./icons/brush.XPM"
# define ICON_LINE	"./icons/line.XPM"
# define ICON_SQUARE "./icons/square.XPM"
# define ICON_ELLIPSE "./icons/ellipse.XPM"
# define ICON_BUCKET "./icons/bucket.XPM"
# define ICON_EYEDROP "./icons/eyedrop.XPM"
# define PALLET_H 199
# define PALLET_W 234

typedef struct	s_point
{
	int		x;
	int		y;
	double	dx;
	double	dy;
}				t_point;

typedef	struct	s_ellipse
{
	t_point		det;
	t_point		pos;
	t_point		m;
}				t_ellipse;

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
	int			ht;
	int			wd;
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
	int			brush_size;

	t_img		*color_gui;
	int			color_gui_on;
	t_img		*c_ui_p;
	t_img		*c_ui_s;
	void		*active_icon;
	t_img		*c_ui_tool;
	t_img		*icon_brush;
	t_img		*icon_line;
	t_img		*icon_square;
	t_img		*icon_ellipse;
	t_img		*icon_bucket;
	t_img		*icon_eyedrop;

	t_stack		*buf;
	t_stack		*redo_buf;
	int			action_status;
	int			mode;
	int			prev_mode;
}				t_mlx;

/*
** img.c
*/
void			img_set_pixel(t_img *img, int x, int y, int color);
t_img			*del_img(t_mlx *mlx, t_img *img);
t_img			*new_img(t_mlx *mlx, int w, int h);
void			fill_img(t_img *img, int color, int wd, int ht);
t_img			*xpm_image(char *xpm, t_mlx *mlx);

/*
** mouse.c
*/
int				hook_mouse_down(int button, int x, int y, t_mlx *mlx);
int				hook_mouse_up(int button, int x, int y, t_mlx *mlx);
int				hook_mouse_move(int x, int y, t_mlx *mlx);

/*
** main.c
*/
void			error(char *str);
int				hook_close(void);

/*
** init_store.c
*/
t_mlx			*init(void);
t_mlx			*mlx_dispose(t_mlx *mlx);

/*
** render.c
*/
int				render(t_mlx *mlx);

/*
** keyboard.c
*/
int				hook_key_up(int button, t_mlx *mlx);
int				hook_key_down(int button, t_mlx *mlx);

/*
** draw.c
*/
t_point			*new_point(int x, int y);
void			fill_brush_radius(t_mlx *mlx, int x, int y);

/*
** draw_line.c
*/
void			draw_line(t_mlx *mlx, t_point p1, t_point p2);
void			draw_rectangle(t_mlx *mlx, t_point p1, t_point p2);

/*
** draw_ellipse.c
*/
void			get_ellipse_params(t_mlx *mlx, int x2, int y2);
void			draw_ellipse(t_mlx *mlx, t_point c, t_point r);
void			draw_bucket(t_mlx *mlx, int x, int y);

/*
** frame_buffer.c
*/
void			undo(t_mlx *mlx);
void			redo(t_mlx *mlx);
void			stack_dispose(t_mlx *mlx, t_stack *stack);
void			update_buf(t_mlx *mlx);
void			set_mlx_img_ptr(t_mlx *mlx);

/*
** color_pick_gui.c
*/
void			color_pick_gui(t_mlx *mlx, int x, int y, int button);
void			color_pick(t_mlx *mlx, int x, int y, int button);
void			deploy_color_gui(t_mlx *mlx);
void			hide_color_gui(t_mlx *mlx);

#endif
