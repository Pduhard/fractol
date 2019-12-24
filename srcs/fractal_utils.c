/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractal_utils.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pduhard- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/21 06:55:40 by pduhard-     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 07:49:41 by pduhard-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		init_fractal_param(t_data *data, t_fparam *param, double t_index)
{
	double	f_row_abs;
	double	f_col_abs;

	f_row_abs = ft_fabs(data->row_min - data->row_max);
	f_col_abs = ft_fabs(data->col_min - data->col_max);
	param->row_min = data->row_min - (f_row_abs * t_index / (double)NB_THREADS);
	param->row_max = param->row_min - (f_row_abs / (double)NB_THREADS);
	param->col_min = data->col_min;
	param->col_max = data->col_max;
	param->row_start = (double)WIN_HEIGHT * t_index / (double)NB_THREADS;
	param->row_end = (double)WIN_HEIGHT * (t_index + 1.0) / (double)NB_THREADS;
	param->row_inc = f_row_abs / (double)WIN_HEIGHT;
	param->col_inc = f_col_abs / (double)WIN_WIDTH;
	param->iter = data->iter;
	param->mlx = data->mlx;
	ft_memcpy(param->color_set, data->color_set[data->color_set_index
		% COLOR_SET_NBR], sizeof(int) * COLOR_SET_SIZE);
}
