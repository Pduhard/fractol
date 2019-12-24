/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sepiensky.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pduhard- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/21 07:41:49 by pduhard-     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 08:38:09 by pduhard-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_sepiensky_check_center(double *min,
				double *max, double val, int r_c)
{
	double	third;

	third = (ft_fabs(*min - *max) / 3.0);
	if ((r_c && val > *min + third) || (!r_c && val < *min - third))
	{
		if ((!r_c && val > *min - 2.0 * third)
			|| (r_c && val < *min + 2.0 * third))
		{
			*min = r_c ? *min + third : *min - third;
			*max = r_c ? *max - third : *max + third;
			return (1);
		}
		*min = r_c ? *min + (2.0 * third) : *min - (2.0 * third);
	}
	else
		*max = r_c ? *max - (2.0 * third) : *max + (2.0 * third);
	return (0);
}

static int	ft_sepiensky_check_in(t_complex val, int iter, t_fparam *param)
{
	double	r_min;
	double	r_max;
	double	c_min;
	double	c_max;

	r_min = 1;
	r_max = -1;
	c_min = -1;
	c_max = 1;
	while (iter-- > 0 && (c_max - c_min) * (double)WIN_WIDTH
		/ (param->col_max - param->col_min) > 1.0)
		if (ft_sepiensky_check_center(&r_min, &r_max, val.imag, 0)
			+ ft_sepiensky_check_center(&c_min, &c_max, val.real, 1) == 2)
			return (iter);
	return (0);
}

static void	*init_sepiensky_param(t_data *data)
{
	t_fparam	*param;
	t_fparam	*param_cpy;
	int			i_thread;

	if (!data->fractal_param
		&& !(data->fractal_param = malloc(sizeof(t_fparam) * NB_THREADS)))
		return (NULL);
	param = data->fractal_param;
	param_cpy = param;
	i_thread = 0;
	while (i_thread < NB_THREADS)
	{
		init_fractal_param(data, param, (double)i_thread);
		++param;
		++i_thread;
	}
	return (param_cpy);
}

static void	*ft_run_sepiensky(void *data)
{
	int			col;
	int			color;
	t_complex	p;
	t_fparam	*param;

	param = (t_fparam *)data;
	p.imag = param->row_min;
	while (param->row_start < param->row_end)
	{
		col = -1;
		p.real = param->col_min;
		while (++col < WIN_WIDTH)
		{
			if ((color = (ft_sepiensky_check_in(p, param->iter, param)))
				&& p.real > -1 && p.real < 1 && p.imag > -1 && p.imag < 1)
				ft_put_pixel(param->row_start, col, param->mlx->img_str,
					param->color_set[color * param->row_start
						* WIN_HEIGHT % COLOR_SET_SIZE]);
			p.real += param->col_inc;
		}
		++param->row_start;
		p.imag -= param->row_inc;
	}
	pthread_exit(NULL);
	return (NULL);
}

void		ft_sepiensky(t_data *data)
{
	t_fparam	*param;
	pthread_t	threads[NB_THREADS];
	int			i;
	int			ret;

	i = 0;
	data->fractal_param = init_sepiensky_param(data);
	param = (t_fparam *)(data->fractal_param);
	while (i < NB_THREADS)
	{
		ret = pthread_create(&(threads[i]), NULL,
			ft_run_sepiensky, (void *)(&(param[i])));
		if (ret)
			exit(EXIT_FAILURE);
		++i;
	}
	i = 0;
	while (i < NB_THREADS)
		pthread_join(threads[i++], NULL);
}
