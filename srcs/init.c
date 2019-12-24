/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pduhard- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 19:14:33 by pduhard-     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 20:24:49 by pduhard-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static t_mlx	*ft_init_mlx(void)
{
	t_mlx	*mlx;

	if (!(mlx = malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "fractl");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT);
	mlx->img_str = (int *)mlx_get_data_addr(mlx->img_ptr,
			&(mlx->bpp), &(mlx->s_l), &(mlx->endian));
	return (mlx);
}

static t_data	*ft_init_julia(void)
{
	t_data	*data;

	if (!(data = malloc(sizeof(t_data))))
		return (NULL);
	data->row_min = 1.75;
	data->row_max = -1.75;
	data->col_min = -1.75;
	data->col_max = 1.75;
	data->fractal_fct = &ft_julia;
	data->mouse_lock = 0;
	return (data);
}

static t_data	*ft_init_mandelbrot(void)
{
	t_data	*data;

	if (!(data = malloc(sizeof(t_data))))
		return (NULL);
	data->row_min = 1.5;
	data->row_max = -1.5;
	data->col_min = -2;
	data->col_max = 1;
	data->fractal_fct = &ft_mandelbrot;
	return (data);
}

static t_data	*ft_init_sepiensky(void)
{
	t_data	*data;

	if (!(data = malloc(sizeof(t_data))))
		return (NULL);
	data->row_min = 1;
	data->row_max = -1;
	data->col_min = -1;
	data->col_max = 1;
	data->fractal_fct = &ft_sepiensky;
	return (data);
}

t_data			*ft_init_data(char *name)
{
	t_data	*data;

	if (!ft_strcmp(name, "mandelbrot"))
		data = ft_init_mandelbrot();
	else if (!ft_strcmp(name, "julia"))
		data = ft_init_julia();
	else if (!ft_strcmp(name, "sepiensky"))
		data = ft_init_sepiensky();
	else
	{
		ft_fdprintf(2, "%s", VALID_FRACT_ERR);
		return (NULL);
	}
	if (!data)
		return (NULL);
	if (!(data->mlx = ft_init_mlx()))
	{
		free(data);
		return (NULL);
	}
	ft_get_colors_set(data->color_set);
	data->iter = DFLT_ITER;
	data->fractal_param = NULL;
	data->color_set_index = 1;
	return (data);
}
