/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pduhard- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/20 00:50:10 by pduhard-     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 08:37:06 by pduhard-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_julia_check_in(t_complex maped, int iter, t_complex cst)
{
	if (iter)
	{
		maped = ft_complex_add(ft_complex_mult(maped, maped), cst);
		if (ft_complex_module(maped) > 5.0)
			return (iter);
		return (ft_julia_check_in(maped, iter - 1, cst));
	}
	else if (ft_complex_module(maped) > 5.0)
		return (1);
	return (0);
}

static void	*init_julia_param(t_data *data)
{
	t_fparam	*param;
	t_fparam	*param_cpy;
	int			t_index;

	t_index = 0;
	if (!data->fractal_param
		&& !(data->fractal_param = malloc(sizeof(t_fparam) * NB_THREADS)))
		return (NULL);
	param = data->fractal_param;
	param_cpy = param;
	while (t_index < NB_THREADS)
	{
		init_fractal_param(data, param, (double)t_index);
		param->cst.real = (double)data->mouse_x * 2.0 / (double)WIN_WIDTH - 1;
		param->cst.imag = (double)data->mouse_y * 2.0 / (double)WIN_HEIGHT - 1;
		++param;
		++t_index;
	}
	return (param_cpy);
}

static void	*ft_run_julia(void *data)
{
	int			col;
	int			color;
	t_complex	val;
	t_fparam	*param;

	param = (t_fparam *)data;
	val.imag = param->row_min;
	while (param->row_start < param->row_end)
	{
		col = 0;
		val.real = param->col_min;
		while (col < WIN_WIDTH)
		{
			if ((color = (ft_julia_check_in(val, param->iter, param->cst))))
				ft_put_pixel(param->row_start, col, param->mlx->img_str,
					param->color_set[(param->iter - color) % COLOR_SET_SIZE]);
			++col;
			val.real += param->col_inc;
		}
		++param->row_start;
		val.imag -= param->row_inc;
	}
	pthread_exit(NULL);
	return (NULL);
}

void		ft_julia(t_data *data)
{
	t_fparam	*param;
	pthread_t	threads[NB_THREADS];
	int			i;
	int			ret;

	i = 0;
	data->fractal_param = init_julia_param(data);
	param = (t_fparam *)(data->fractal_param);
	while (i < NB_THREADS)
	{
		ret = pthread_create(&(threads[i]), NULL,
			ft_run_julia, (void *)(&(param[i])));
		if (ret)
			exit(EXIT_FAILURE);
		++i;
	}
	i = 0;
	while (i < NB_THREADS)
		pthread_join(threads[i++], NULL);
}
