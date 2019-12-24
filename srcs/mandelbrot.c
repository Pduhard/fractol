/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pduhard- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 19:10:07 by pduhard-     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 08:36:03 by pduhard-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_mandelbrot_check_in(t_complex maped, int iter, t_complex cst)
{
	if (iter)
	{
		maped = ft_complex_add(ft_complex_mult(maped, maped), cst);
		if (ft_complex_module(maped) > 5.0)
			return (iter);
		return (ft_mandelbrot_check_in(maped, iter - 1, cst));
	}
	else if (ft_complex_module(maped) > 5.0)
		return (1);
	return (0);
}

static void	*init_mandelbrot_param(t_data *data)
{
	t_fparam	*param;
	t_fparam	*param_cpy;
	int			i;

	i = 0;
	if (!data->fractal_param
		&& !(data->fractal_param = malloc(sizeof(t_fparam) * NB_THREADS)))
		return (NULL);
	param = data->fractal_param;
	param_cpy = param;
	while (i < NB_THREADS)
	{
		init_fractal_param(data, param, (double)i);
		param->cst.real = 0;
		param->cst.imag = 0;
		++param;
		++i;
	}
	return (param_cpy);
}

static void	*ft_run_mandelbrot(void *data)
{
	int			col;
	int			clr;
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
			if ((clr = (ft_mandelbrot_check_in(param->cst, param->iter, val))))
				ft_put_pixel(param->row_start, col, param->mlx->img_str,
					param->color_set[(param->iter - clr) % COLOR_SET_SIZE]);
			++col;
			val.real += param->col_inc;
		}
		++param->row_start;
		val.imag -= param->row_inc;
	}
	pthread_exit(NULL);
	return (NULL);
}

void		ft_mandelbrot(t_data *data)
{
	t_fparam	*param;
	pthread_t	threads[NB_THREADS];
	int			i;
	int			ret;

	i = 0;
	data->fractal_param = init_mandelbrot_param(data);
	param = (t_fparam *)(data->fractal_param);
	while (i < NB_THREADS)
	{
		ret = pthread_create(&(threads[i]), NULL,
			ft_run_mandelbrot, (void *)(&(param[i])));
		if (ret)
			exit(EXIT_FAILURE);
		++i;
	}
	i = 0;
	while (i < NB_THREADS)
		pthread_join(threads[i++], NULL);
}
