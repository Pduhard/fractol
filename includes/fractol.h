/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pduhard- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 22:51:16 by pduhard-     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 20:23:53 by pduhard-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>

# define VALID_FRACT_ERR "Valid Options: -mandelbrot -julia -sepiensky\n"
# define WIN_WIDTH	1234
# define WIN_HEIGHT	1234

# define NB_THREADS	8
# define JULIA_SENSI	5
# define DFLT_ITER	50
# define COLOR_SET_NBR	 3
# define COLOR_SET_SIZE	 10

typedef struct	s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_str;
	int			bpp;
	int			s_l;
	int			endian;
}				t_mlx;

typedef struct	s_fparam
{
	double		row_min;
	double		row_max;
	double		col_min;
	double		col_max;
	int			row_start;
	int			row_end;
	int			iter;
	t_mlx		*mlx;
	int			color_set[COLOR_SET_SIZE];
	double		row_inc;
	double		col_inc;
	t_complex	cst;
}				t_fparam;

typedef struct	s_data
{
	void		(*fractal_fct)(struct s_data *);
	t_fparam	*fractal_param;
	t_mlx		*mlx;
	int			iter;
	double		row_min;
	double		row_max;
	double		col_min;
	double		col_max;
	int			mouse_x;
	int			mouse_y;
	int			mouse_lock;
	int			color_set[COLOR_SET_NBR][COLOR_SET_SIZE];
	int			color_set_index;
}				t_data;

t_data			*ft_init_data(char *name);
void			ft_mandelbrot(t_data *data);
void			ft_julia(t_data *data);
void			ft_sepiensky(t_data *data);
void			ft_put_pixel(int row, int col, int *img_str, int color);
int				ft_print_loop_image(void *param);
int				ft_key_press(int keycode, void *param);
int				ft_mouse_hook(int button, int x, int y, void *param);
int				ft_moov_hook(int x, int y, void *param);
int				ft_print_loop_image(void *param);
void			init_fractal_param(t_data *data,
					t_fparam *param, double t_index);
void			ft_get_colors_set(int color_set[COLOR_SET_NBR][COLOR_SET_SIZE]);
double			ft_complex_module(t_complex a);
t_complex		ft_complex_add(t_complex a, t_complex b);
t_complex		ft_complex_mult(t_complex a, t_complex b);
void			ft_free_data(t_data *data);

#endif
